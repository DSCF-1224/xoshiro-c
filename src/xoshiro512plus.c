#include "xoshiro512plus.h"


void copy_state ( struct Xoshiro512plus *const dst , const struct Xoshiro512plus *const src )
{
	#include "include/copy_state.c"
}


void fill_state ( struct Xoshiro512plus *const generator , const uint64_t src )
{
	#include "include/fill_state.c"
}


void jump_state ( struct Xoshiro512plus *const generator , const bool is_long_jump )
{
	#include "include/jump_state/xoshiro512.c"
}


void jump_state_core ( struct Xoshiro512plus *const generator , const uint64_t *const JUMP , const size_t given_size_state )
{
	/* local variable */
	struct Xoshiro512plus workspace;

	#include "include/jump_state/core0512.c"
}


size_t state_size ( const struct Xoshiro512plus *const generator )
{
	#include "include/state_size.c"
}


uint64_t sample_uint64 ( struct Xoshiro512plus *const generator )
{
	// STEP.01
	const uint64_t result = (*generator).state[0] + (*generator).state[2];

	// STEP.02
	update_state( generator );

	// STEP.END
	return result;
}


void update_state ( struct Xoshiro512plus *const generator )
{
	#include "include/update_state/xoshiro512.c"
}


bool validate_state ( const struct Xoshiro512plus *const generator )
{
	#include "include/validate_state.c"
}

/* EOF */
