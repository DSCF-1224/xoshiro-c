// STEP.01
fill_state( &workspace , UINT64_C(0) );

// STEP.02
for (int i = 0 ; i < given_size_state ; ++i)
for (int b = 0 ; b < 64               ; ++b)
{
	// STEP.01
	if ( JUMP[i] & UINT64_C(1) << b )
	{
		for (int j = 0; j < given_size_state; ++j)
		{
			workspace.state[j] ^= (*generator).state[j];
		}
	}

	// STEP.02
	update_state(generator);
}

// STEP.03
copy_state( generator , &workspace );

// STEP.END
return;

/* EOF */
