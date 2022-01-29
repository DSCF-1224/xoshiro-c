#include "xoshiro256plus.h"


void copy_state ( struct Xoshiro256plus *const dest , const struct Xoshiro256plus *const src )
{
	copy_state_xoshiro( state_size(dest) , (*dest).state , (*src).state );
	return;
}


void fill_state ( struct Xoshiro256plus *const generator , const uint64_t src )
{
	fill_state_xoshiro( state_size(generator) , (*generator).state , src );
	return;
}


void jump_state ( struct Xoshiro256plus *const generator , const bool is_long_jump )
{
	// STEP.01
	if   (is_long_jump) jump_state_core_xoshiro256( state_size(generator) , (*generator).state , XOSHIRO_0256_JUMP_LONG );
	else                jump_state_core_xoshiro256( state_size(generator) , (*generator).state , XOSHIRO_0256_JUMP      );

	// STEP.END
	return;
}


size_t state_size ( const struct Xoshiro256plus *const generator )
{
	#include "include/state_size.c"
}


uint64_t sample_uint64 ( struct Xoshiro256plus *const generator )
{
	// STEP.01
	const uint64_t result = (*generator).state[0] + (*generator).state[3];

	// STEP.02
	update_state( generator );

	// STEP.END
	return result;
}


void update_state ( struct Xoshiro256plus *const generator )
{
	update_state_xoshiro256( (*generator).state );
	return;
}


bool validate_state ( const struct Xoshiro256plus *const generator )
{
	return validate_state_xoshiro( state_size(generator) , (*generator).state );
}

/* EOF */
