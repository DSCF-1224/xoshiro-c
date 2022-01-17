int set_sample_size ( const int *const argc , const char *const argv[] , size_t *const sample_size )
{
	// STEP.01
	// check the number of given command line arguments
	if ( *argc <= LOC_SAMPLE_SIZE )
	{
		fprintf( stderr , "%s %d%s\n" , "The number of command line arguments must be greater than" , LOC_SAMPLE_SIZE , "." );
		return EXIT_FAILURE + 1;
	}

	// STEP.02
	// check the given number of samples to print
	if ( atoi( argv[LOC_SAMPLE_SIZE] ) < MINVAL_SAMPLE_SIZE )
	{
		fprintf( stderr , "%s\n" , "The number of samples must be greater than 0." );
		return EXIT_FAILURE + 2;
	}

	// STEP.03
	// save the given number of samples to print
	*sample_size = atoi( argv[LOC_SAMPLE_SIZE] );

	// STEP.END
	return EXIT_SUCCESS;
}
