#include "xoshiro256plusplus.h"


void copy_state ( struct Xoshiro256plusplus *const dst , const struct Xoshiro256plusplus *const src )
{
	// STEP.01
	for (size_t itr_stat = 0; itr_stat < state_size(dst); ++itr_stat)
	{
		(*dst).state[itr_stat] = (*src).state[itr_stat];
	}

	// STEP.END
	return;
}


void fill_state ( struct Xoshiro256plusplus *const generator , const uint64_t src )
{
	memset( &(*generator).state[0] , src , state_size(generator) );
	return;
}


void jump_state ( struct Xoshiro256plusplus *const generator , const bool is_long_jump )
{
	/* local variable */
	const static uint64_t JUMP      [] = { 0x180ec6d33cfd0aba, 0xd5a61266f0c9392c, 0xa9582618e03fc9aa, 0x39abdc4529b1661c };
	const static uint64_t LONG_JUMP [] = { 0x76e15d3efefdcbbf, 0xc5004e441c522fb3, 0x77710069854ee241, 0x39109bb02acbe635 };

	// STEP.01
	if   (is_long_jump) jump_state_core( generator , LONG_JUMP , state_size(generator) );
	else                jump_state_core( generator , JUMP      , state_size(generator) );

	// STEP.END
	return;
}


void jump_state_core ( struct Xoshiro256plusplus *const generator , const uint64_t *const JUMP , const size_t given_size_state )
{
	/* local variable */
	static struct Xoshiro256plusplus workspace;

	// STEP.01
	fill_state( &workspace , 0 );

	// STEP.02
	for (int i = 0 ; i < given_size_state ; i++)
	for (int b = 0 ; b < 64               ; b++)
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

	// STEP.02
	copy_state( generator , &workspace );

	// STEP.END
	return;
}


size_t state_size ( const struct Xoshiro256plusplus *const generator )
{
	return ( sizeof (*generator).state ) / ( sizeof *(*generator).state );
}


uint64_t sample_uint64 ( struct Xoshiro256plusplus *const generator )
{
	// STEP.01
	const uint64_t result = rotl_uint64( (*generator).state[0] + (*generator).state[3] , 23 ) + (*generator).state[0];

	// STEP.02
	update_state( generator );

	// STEP.END
	return result;
}


void update_state ( struct Xoshiro256plusplus *const generator )
{
	// STEP.01
	const uint64_t workspace = ( (*generator).state[1] << 17 );

	// STEP.02
	(*generator).state[2] ^= (*generator).state[0];
	(*generator).state[3] ^= (*generator).state[1];
	(*generator).state[1] ^= (*generator).state[2];
	(*generator).state[0] ^= (*generator).state[3];

	// STEP.03
	(*generator).state[2] ^= workspace;

	// STEP.04
	(*generator).state[3] = rotl_uint64( (*generator).state[3] , 45 );

	// STEP.END
	return;
}


bool validate_state ( const struct Xoshiro256plusplus *const generator )
{
	// STEP.01
	// initialize the return value of this function
	bool validity = false;

	// STEP.02
	// check the given state
	for ( size_t itr_stat = 0; itr_stat < state_size(generator); ++itr_stat )
	{
		validity = validity | ( (*generator).state[itr_stat] != 0 );
	}

	// STEP.END
	return validity;
}

/* EOF */
