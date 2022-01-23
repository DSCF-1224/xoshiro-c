// STEP.01
memset( workspace , 0 , (sizeof workspace) );

// STEP.02
for ( int itr_st1 = 0 ; itr_st1 < given_size_state ; ++itr_st1 )
for ( int itr_bit = 0 ; itr_bit < 64               ; ++itr_bit )
{
	// STEP.01
	if ( JUMP[itr_st1] & UINT64_C(1) << itr_bit )
	{
		for ( int itr_st2 = 0; itr_st2 < given_size_state; ++itr_st2 )
		{
			const int address = modify_state_address( &(*generator).address.fst , &itr_st2 );
			workspace[itr_st2] ^= (*generator).state[ address ];
		}
	}

	// STEP.02
	update_state(generator);
}

// STEP.03
for ( int itr_st = 0 ; itr_st < given_size_state ; ++itr_st )
{
	const int address = modify_state_address( &(*generator).address.fst , &itr_st );
	(*generator).state[ address ] = workspace[itr_st];
}

// STEP.END
return;

/* EOF */
