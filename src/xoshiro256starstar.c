#include "xoshiro256starstar.h"


void copy_state ( struct Xoshiro256starstar *const dest , const struct Xoshiro256starstar *const src )
{
	copy_state_xoshiro( state_size(dest) , (*dest).state , (*src).state );
	return;
}


void fill_state ( struct Xoshiro256starstar *const generator , const uint64_t src )
{
	fill_state_xoshiro( state_size(generator) , (*generator).state , src );
	return;
}


void jump_state ( struct Xoshiro256starstar *const generator , const bool is_long_jump )
{
	// STEP.01
	if   (is_long_jump) jump_state_core_xoshiro256( state_size(generator) , (*generator).state , XOSHIRO_0256_JUMP_LONG );
	else                jump_state_core_xoshiro256( state_size(generator) , (*generator).state , XOSHIRO_0256_JUMP      );

	// STEP.END
	return;
}


size_t state_size ( const struct Xoshiro256starstar *const generator )
{
	#include "include/state_size.c"
}


uint64_t sample_uint64 ( struct Xoshiro256starstar *const generator )
{
	// STEP.01
	const uint64_t result = rotl_uint64( (*generator).state[1] * UINT64_C(5) , 7 ) * UINT64_C(9);

	// STEP.02
	update_state( generator );

	// STEP.END
	return result;
}


void update_state ( struct Xoshiro256starstar *const generator )
{
	update_state_xoshiro256( (*generator).state );
	return;
}


bool validate_state ( const struct Xoshiro256starstar *const generator )
{
	return validate_state_xoshiro( state_size(generator) , (*generator).state );
}

/* EOF */
