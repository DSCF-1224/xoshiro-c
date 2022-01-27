#include "xoroshiro1024plusplus.h"


void copy_state ( struct Xoroshiro1024plusplus *const dst , const struct Xoroshiro1024plusplus *const src )
{
	copy_state_value_xoroshiro1024( &(*dst).state , &(*src).state );
	return;
}


void fill_state ( struct Xoroshiro1024plusplus *const generator , const uint64_t src )
{
	fill_state_value_xoroshiro1024( &(*generator).state , src );
	return;
}


void initialize_generator ( struct Xoroshiro1024plusplus *const generator , const int address )
{
	initialize_address_xoroshiro1024( &(*generator).address , address );
	return;
}


void jump_state ( struct Xoroshiro1024plusplus *const generator , const bool is_long_jump )
{
	// STEP.01
	if   (is_long_jump) jump_state_core_xoroshiro1024( &(*generator).address , &(*generator).state , &(*generator).workspace , XOROSHIRO_1024_JUMP_LONG );
	else                jump_state_core_xoroshiro1024( &(*generator).address , &(*generator).state , &(*generator).workspace , XOROSHIRO_1024_JUMP      );

	// STEP.END
	return;
}


size_t state_size ( const struct Xoroshiro1024plusplus *const generator )
{
	return state_size_xoroshiro1024( &(*generator).state );
}


uint64_t sample_uint64 ( struct Xoroshiro1024plusplus *const generator )
{
	// STEP.01
	update_state_pre( generator );

	// STEP.02
	const uint64_t result = rotl_uint64( (*generator).workspace.fst + (*generator).workspace.lst , 23 ) + (*generator).workspace.lst;

	// STEP.03
	update_state_pst( generator );

	// STEP.END
	return result;
}


void update_state ( struct Xoroshiro1024plusplus *const generator )
{
	update_state_pre( generator );
	update_state_pst( generator );
	return;
}


void update_state_pre ( struct Xoroshiro1024plusplus *const generator )
{
	update_state_pre_xoroshiro1024( &(*generator).address , &(*generator).state , &(*generator).workspace );
	return;
}


void update_state_pst ( struct Xoroshiro1024plusplus *const generator )
{
	update_state_pst_xoroshiro1024( &(*generator).address , &(*generator).state , &(*generator).workspace );
	return;
}


bool validate_state ( const struct Xoroshiro1024plusplus *const generator )
{
	return validate_state_xoroshiro1024( &(*generator).state );
}

/* EOF */
