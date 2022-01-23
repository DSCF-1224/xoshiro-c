#include "xoroshiro128starstar.h"


void copy_state ( struct Xoroshiro128starstar *const dst , const struct Xoroshiro128starstar *const src )
{
	#include "include/copy_state.c"
}


void fill_state ( struct Xoroshiro128starstar *const generator , const uint64_t src )
{
	#include "include/fill_state.c"
}


void jump_state ( struct Xoroshiro128starstar *const generator , const bool is_long_jump )
{
	#include "include/jump_state/xoroshiro128starstar.c"
}


void jump_state_core ( struct Xoroshiro128starstar *const generator , const uint64_t *const JUMP , const size_t given_size_state )
{
	/* local variable */
	struct Xoroshiro128starstar workspace;

	#include "include/jump_state/core0128.c"
}


size_t state_size ( const struct Xoroshiro128starstar *const generator )
{
	#include "include/state_size.c"
}


uint64_t sample_uint64 ( struct Xoroshiro128starstar *const generator )
{
	// STEP.01
	const uint64_t result = rotl_uint64( (*generator).state[0] * UINT64_C(5) , 7 ) * UINT64_C(9);

	// STEP.02
	update_state( generator );

	// STEP.END
	return result;
}


void update_state ( struct Xoroshiro128starstar *const generator )
{
	struct Xoroshiro128starstar workspace;

	#include "include/update_state/xoroshiro128starstar.c"
}


bool validate_state ( const struct Xoroshiro128starstar *const generator )
{
	#include "include/validate_state.c"
}

/* EOF */
