#include "xoroshiro128plusplus.h"


void copy_state ( struct Xoroshiro128plusplus *const dst , const struct Xoroshiro128plusplus *const src )
{
	#include "include/copy_state.c"
}


void fill_state ( struct Xoroshiro128plusplus *const generator , const uint64_t src )
{
	#include "include/fill_state.c"
}


void jump_state ( struct Xoroshiro128plusplus *const generator , const bool is_long_jump )
{
	#include "include/jump_state/xoroshiro128plusplus.c"
}


void jump_state_core ( struct Xoroshiro128plusplus *const generator , const uint64_t *const JUMP , const size_t given_size_state )
{
	/* local variable */
	struct Xoroshiro128plusplus workspace;

	#include "include/jump_state_core.c"
}


size_t state_size ( const struct Xoroshiro128plusplus *const generator )
{
	#include "include/state_size.c"
}


uint64_t sample_uint64 ( struct Xoroshiro128plusplus *const generator )
{
	// STEP.01
	const uint64_t result = rotl_uint64( (*generator).state[0] + (*generator).state[1] , 17 ) + (*generator).state[0];

	// STEP.02
	update_state( generator );

	// STEP.END
	return result;
}


void update_state ( struct Xoroshiro128plusplus *const generator )
{
	struct Xoroshiro128plusplus workspace;

	#include "include/update_state/xoroshiro128plusplus.c"
}


bool validate_state ( const struct Xoroshiro128plusplus *const generator )
{
	#include "include/validate_state.c"
}

/* EOF */
