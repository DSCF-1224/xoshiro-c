int fprintf_sample ( const int *const argc , const char *const argv[] )
{
	/* variable(s) for the this function */
	FILE*     fstream_save;
	size_t    sample_size;
	Generator generator;
	Generator buffer;

	// STEP.01
	// get the generator state from the command line arguments
	switch ( set_generator_state( argc , argv , &generator ) )
	{
		case EXIT_SUCCESS:
			copy_state( &buffer , &generator );
			break;

		default:
			return EXIT_FAILURE;
	}

	// STEP.02
	// get the number of samples to print from the command line arguments
	switch ( set_sample_size( argc , argv , &sample_size ) )
	{
		case    EXIT_SUCCESS : break;
		default              : return EXIT_FAILURE;
	}

	// STEP.03
	// open a file to save the generator state & generated sample
	if ( ( fstream_save = fopen( FILENAME_SAVE , "w" ) ) == NULL )
	{
		fprintf( stderr , "%s\n" , "Failed to open a file to save generated samples." );
		return EXIT_FAILURE;
	}

	// STEP.04
	// print the samples without a jump process
	fprintf_sample_unit( fstream_save , &sample_size , &generator );

	// STEP.05
	// print the samples with a (short) jump
	copy_state( &generator , &buffer );
	jump_state( &generator , false );
	fprintf_sample_unit( fstream_save , &sample_size , &generator );

	// STEP.06
	// print the samples with a long jump
	copy_state( &generator , &buffer );
	jump_state( &generator , true );
	fprintf_sample_unit( fstream_save , &sample_size , &generator );

	// STEP.END
	return EXIT_SUCCESS;
}
