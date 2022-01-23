#include "xoroshiro1024star.h"


void copy_state ( struct Xoroshiro1024star *const dst , const struct Xoroshiro1024star *const src )
{
	#include "include/copy_state.c"
}


void fill_state ( struct Xoroshiro1024star *const generator , const uint64_t src )
{
	#include "include/fill_state.c"
}


void initialize_generator ( struct Xoroshiro1024star *const generator )
{
	(*generator).address.fst = 0;
	return;
}


void jump_state ( struct Xoroshiro1024star *const generator , const bool is_long_jump )
{
	#include "include/jump_state/xoroshiro1024.c"
}


void jump_state_core ( struct Xoroshiro1024star *const generator , const uint64_t *const JUMP , const size_t given_size_state )
{
	/* local variable */
	uint64_t workspace[given_size_state];

	#include "include/jump_state/core1024.c"
}


size_t state_size ( const struct Xoroshiro1024star *const generator )
{
	#include "include/state_size.c"
}


uint64_t sample_uint64 ( struct Xoroshiro1024star *const generator )
{
	// STEP.01
	update_state_pre( generator );

	// STEP.02
	const uint64_t result = (*generator).workspace.fst * 0x9e3779b97f4a7c13;

	// STEP.03
	update_state_pst( generator );

	// STEP.END
	return result;
}


void update_state ( struct Xoroshiro1024star *const generator )
{
	update_state_pre( generator );
	update_state_pst( generator );
	return;
}


void update_state_pre ( struct Xoroshiro1024star *const generator )
{
	#include "include/update_state/xoroshiro1024/pre.c"
}


void update_state_pst ( struct Xoroshiro1024star *const generator )
{
	#include "include/update_state/xoroshiro1024/pst.c"
}


bool validate_state ( const struct Xoroshiro1024star *const generator )
{
	#include "include/validate_state.c"
}

/* EOF */
