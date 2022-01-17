int set_generator_state ( const int *const argc , const char *const argv[] , Generator *const generator )
{
	// STEP.01
	// check the number of given command line arguments
	if ( *argc < ( loc_state( state_size(generator) ) ) )
	{
		fprintf( stderr , "%s %ld%s\n" , "The number of command line arguments must be greater than" , ( loc_state( state_size(generator) ) ) , "." );
		fprintf_state_size( stderr , generator );
		return EXIT_FAILURE + 1;
	}

	// STEP.02
	// save the given state of the generator
	for (size_t itr_stat = 0; itr_stat < state_size(generator); ++itr_stat)
	{
		(*generator).state[itr_stat] = atoi( argv[ loc_state(itr_stat) ] );
	}

	// STEP.03
	// check the given state
	if ( !validate_state(generator) )
	{
		fprintf( stderr , "%s\n" , "At least one state must have a non-zero value." );

		for (size_t itr_stat = 0; itr_stat < state_size(generator); ++itr_stat)
		{
			fprintf( stderr , "%2ld %16.16lx\n" , itr_stat , (*generator).state[itr_stat] );
		}

		return EXIT_FAILURE + 3;
	}

	// STEP.END
	return EXIT_SUCCESS;
}
