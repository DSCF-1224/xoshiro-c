#include "xoshiro256.h"


void jump_state_core_xoshiro256 ( const size_t state_size , uint64_t *const state_value , const uint64_t *const jump_parameter )
{
	/* variables for this function */
	uint64_t workspace[state_size];

	// STEP.01
	// initialize the work space
	fill_state_xoshiro( state_size , workspace , UINT64_C(0) );

	// STEP.02
	// jump the generator state
	for ( size_t itr_st1 = 0; itr_st1 < state_size; ++itr_st1 )
	{
		for ( size_t itr_bit = 0; itr_bit < 64; ++itr_bit )
		{
			// STEP.01
			if ( jump_parameter[itr_st1] & (UINT64_C(1) << itr_bit) )
			{
				for ( size_t itr_st2 = 0; itr_st2 < state_size; ++itr_st2 )
				{
					workspace[itr_st2] ^= state_value[itr_st2];
				}
			}

			// STEP.02
			update_state_xoshiro256( state_value );
		}
	}

	// STEP.03
	// update the generator state using jumped one
	copy_state_xoshiro( state_size , state_value , workspace );

	// STEP.END
	return;
}


void update_state_xoshiro256 ( uint64_t *const state_value )
{
	// STEP.01
	const uint64_t workspace = ( state_value[1] << 17 );

	// STEP.02
	state_value[2] ^= state_value[0];
	state_value[3] ^= state_value[1];
	state_value[1] ^= state_value[2];
	state_value[0] ^= state_value[3];

	// STEP.03
	state_value[2] ^= workspace;

	// STEP.04
	state_value[3] = rotl_uint64( state_value[3] , 45 );

	// STEP.END
	return;
}

/* EOF */
