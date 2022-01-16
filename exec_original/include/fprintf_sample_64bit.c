// [objective]
// get the number of samples to print
// from the command line arguments
int extract_sample_size ( int const *const argc , const char *const argv[] , size_t *const sample_size )
{
	// STEP.01
	// check the number of given line command arguments
	if ( *argc < 2 )
	{
		fprintf( stderr , "%s\n" , "The number of command line arguments must be greater than 1." );
		return EXIT_FAILURE + 1;
	}

	// STEP.02
	// check the given number of samples to print
	if ( atoi( argv[1] ) < 1 )
	{
		fprintf( stderr , "%s\n" , "The number of samples must be greater than 0." );
		return EXIT_FAILURE + 2;
	}

	// STEP.03
	// save the given number of samples to print
	*sample_size = atoi( argv[1] );

	// STEP.END
	return EXIT_SUCCESS;
}


// [objective]
// export the number of states of the generator
size_t state_size (void)
{
	return sizeof s / sizeof *s;
}


// [objective]
// validate the states of the generator
// given from the command line arguments
bool validate_state ( const uint64_t const* state )
{
	// STEP.01
	// initialize the return value of this function
	bool validity = false;

	// STEP.02
	// check the given state
	for (size_t itr_stat = 0; itr_stat < state_size(); itr_stat++)
	{
		validity = validity | ( state[itr_stat] != 0 );
	}

	// STEP.END
	return validity;
}


// [objective]
// display the number of states of the generator
int fprintf_state_size ( FILE *const file_ptr )
{
	fprintf( file_ptr , "%s %ld%s\n" , "The number of state is" , state_size() , "." );
}


// [objective]
// set the generator state
// using values given as the command line arguments
int set_generator_state ( int const *const argc , const char *const argv[] , size_t *const state )
{
	// STEP.01
	// check the number of given line command arguments
	if ( *argc < ( 2 + state_size() ) )
	{
		fprintf( stderr , "%s %ld%s\n" , "The number of command line arguments must be greater than" , ( 2 + state_size() ) , "." );
		fprintf_state_size( stderr );
		return EXIT_FAILURE + 1;
	}

	// STEP.02
	// save the given state of the generator
	for (size_t itr_stat = 0; itr_stat < state_size(); itr_stat++)
	{
		state[itr_stat] = atoi( argv[itr_stat + 2] );
	}

	// STEP.03
	// check the given state
	if ( !validate_state( s ) )
	{
		fprintf( stderr , "%s\n"       , "At least one state must have a non-zero value." );
		fprintf_state_size( stderr );
		return EXIT_FAILURE + 3;
	}

	// STEP.TRUE_END
	return EXIT_SUCCESS;
}


void fprintf_sample_unit ( FILE* fstream_save , const size_t *const sample_size )
{
	// STEP.01
	for (size_t itr_smpl = 1; itr_smpl <= *sample_size; itr_smpl++)
	{
		// STEP.01
		// print the current number of samples
		fprintf( fstream_save , " %20ld" , itr_smpl );

		// STEP.02
		// print the current states of the generator
		for (size_t itr_stat = 0; itr_stat < state_size(); itr_stat++)
		{
			fprintf( fstream_save , " %16.16lx", s[itr_stat] );
		}

		// STEP.03
		// print the sample from the generator
		fprintf( fstream_save , " %16.16lx\n" , next() );

		// STEP.04
		// flush the using stream
		fflush( fstream_save );
	}

	// STEP.TRUE_END
	return;
}


int fprintf_sample ( int const *const argc , const char *const argv[] )
{
	/* variable(s) for the main function */
	FILE*  fstream_save;
	size_t sample_size;

	// STEP.01.01
	if ( set_generator_state ( argc , argv , s ) != EXIT_SUCCESS )
	{
		return EXIT_FAILURE;
	}

	// STEP.01.02
	if ( extract_sample_size ( argc , argv , &sample_size ) != EXIT_SUCCESS )
	{
		return EXIT_FAILURE;
	}

	// STEP.02.01
	fstream_save = fopen( "sample.dat" , "w" );

	// STEP.02.02
	if ( fstream_save == NULL )
	{
		fprintf( stderr , "%s\n" , "Failed to open a file to save generated samples." );
		return EXIT_FAILURE;
	}

	// STEP.03.01
	fprintf_sample_unit( fstream_save , &sample_size );

	// STEP.03.02
	set_generator_state ( argc , argv , s );
	jump();
	fprintf_sample_unit( fstream_save , &sample_size );

	// STEP.03.03
	set_generator_state ( argc , argv , s );
	long_jump();
	fprintf_sample_unit( fstream_save , &sample_size );

	// STEP.04
	// close the used file stream
	fclose( fstream_save );

	// STEP.END
	return EXIT_SUCCESS;
}
