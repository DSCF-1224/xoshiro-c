#include "xoshiro.h"


void copy_state_xoshiro ( const size_t state_size , uint64_t *const dest , const uint64_t *const src )
{
	memmove( dest , src , sizeof(dest) * state_size );
	return;
}


void fill_state_xoshiro ( const size_t state_size , uint64_t *const state_value , const uint64_t source )
{
	for ( size_t itr_stat = 0; itr_stat < state_size; ++itr_stat )
	{
		state_value[itr_stat] = source;
	}

	return;
}


bool validate_state_xoshiro ( const size_t state_size , const uint64_t *const state_value )
{
	// STEP.01
	// initialize the return value of this function
	bool validity = false;

	// STEP.02
	// check the given state
	for ( size_t itr_stat = 0; itr_stat < state_size; ++itr_stat )
	{
		validity = validity || ( state_value[itr_stat] != UINT64_C(0) );
	}

	// STEP.END
	return validity;
}

/* EOF */
