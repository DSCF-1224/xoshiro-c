#include "xoroshiro1024.h"


int modify_state_address ( const struct Xoroshiro1024_Address *const address , const int iterator )
{
	return ( iterator + (*address).fst ) & 15;
}


void copy_state_value_xoroshiro1024 ( struct Xoroshiro1024_State *const dst , const struct Xoroshiro1024_State *const src )
{
	for ( size_t itr_val = 0; itr_val < STATE_SIZE_XOROSHIRO_1024; ++itr_val )
	{
		(*dst).value[itr_val] = (*src).value[itr_val] ;
	}

	return;
}


void fill_state_value_xoroshiro1024 ( struct Xoroshiro1024_State *const generator , const uint64_t src )
{
	for ( size_t itr_val = 0; itr_val < STATE_SIZE_XOROSHIRO_1024; ++itr_val )
	{
		(*generator).value[itr_val] = src;
	}

	return;
}


void initialize_address_xoroshiro1024 ( struct Xoroshiro1024_Address *const instance , const int address )
{
	(*instance).fst = address;
	return;
}


void jump_state_core_xoroshiro1024 ( struct Xoroshiro1024_Address *const address , struct Xoroshiro1024_State *const state , struct Xoroshiro1024_Workspace *const workspace , const uint64_t *const JUMP )
{
	/* local variable */
	struct Xoroshiro1024_State buffer;

	// STEP.01
	memset( buffer.value , 0 , (sizeof buffer.value) );

	// STEP.02
	for ( int itr_st1 = 0 ; itr_st1 < STATE_SIZE_XOROSHIRO_1024 ; ++itr_st1 )
	for ( int itr_bit = 0 ; itr_bit < 64                        ; ++itr_bit )
	{
		// STEP.01
		if ( JUMP[itr_st1] & UINT64_C(1) << itr_bit )
		{
			for ( int itr_st2 = 0; itr_st2 < STATE_SIZE_XOROSHIRO_1024; ++itr_st2 )
			{
				buffer.value[itr_st2] ^= (*state).value[ modify_state_address( address , itr_st2 ) ];
			}
		}

		// STEP.02
		update_state_pre_xoroshiro1024( address , state , workspace );
		update_state_pst_xoroshiro1024( address , state , workspace );
	}

	// STEP.03
	for ( int itr_st = 0 ; itr_st < STATE_SIZE_XOROSHIRO_1024; ++itr_st )
	{
		(*state).value[ modify_state_address( address , itr_st ) ] = buffer.value[ itr_st ];
	}

	// STEP.END
	return;
}


size_t state_size_xoroshiro1024( const struct Xoroshiro1024_State *const state )
{
	return ( sizeof (*state).value ) / ( sizeof *(*state).value );
}


void update_state_pre_xoroshiro1024 ( struct Xoroshiro1024_Address *const address , struct Xoroshiro1024_State *const state , struct Xoroshiro1024_Workspace *const workspace )
{
	// STEP.01
	// update the address of generator state
	(*address).lst = (*address).fst;
	(*address).fst = modify_state_address( address , 1 );

	// STEP.02
	// update the values of the generator state
	(*workspace).fst = (*state).value[ (*address).fst ];
	(*workspace).lst = (*state).value[ (*address).lst ];

	// STEP.END
	return;
}


void update_state_pst_xoroshiro1024 ( struct Xoroshiro1024_Address *const address , struct Xoroshiro1024_State *const state , struct Xoroshiro1024_Workspace *const workspace )
{
	// STEP.01
	(*workspace).lst ^= (*workspace).fst;

	// STEP.02.01
	(*state).value[ (*address).lst ]
	= rotl_uint64( (*workspace).fst , 25 )
	^              (*workspace).lst
	^            ( (*workspace).lst << 27 )
	;

	// STEP.02.02
	(*state).value[ (*address).fst ] = rotl_uint64( (*workspace).lst , 36 );

	// STEP.END
	return;
}


bool validate_state_xoroshiro1024 ( const struct Xoroshiro1024_State *const state )
{
	// STEP.01
	// initialize the return value of this function
	bool validity = false;

	// STEP.02
	// check the given state
	for ( int itr_stat = 0; itr_stat < STATE_SIZE_XOROSHIRO_1024; ++itr_stat )
	{
		validity = validity || ( (*state).value[itr_stat] != 0 );
	}

	// STEP.END
	return validity;
}

/* EOF */
