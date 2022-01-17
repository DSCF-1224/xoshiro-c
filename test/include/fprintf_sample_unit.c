void fprintf_sample_unit ( FILE* fstream_save , const size_t *const sample_size , Generator *const generator )
{
	// STEP.01
	for ( size_t itr_smpl = 1; itr_smpl <= *sample_size; ++itr_smpl )
	{
		// STEP.01
		// print the current number of samples
		fprintf( fstream_save , "%20ld" , itr_smpl );

		// STEP.02
		// print the current generator state
		for ( size_t itr_stat = 0; itr_stat < state_size(generator); ++itr_stat )
		{
			fprintf( fstream_save , " %16.16lx" , (*generator).state[itr_stat] );
		}

		// STEP.03
		// print the current sample from the generator
		fprintf( fstream_save , " %16.16lx\n" , sample_uint64(generator) );

		// STEP.04
		// flush the using stream
		fflush( fstream_save );
	}

	// STEP.END
	return;
}
