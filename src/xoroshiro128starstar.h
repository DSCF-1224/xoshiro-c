#ifndef XOROSHIRO_0128_STARSTAR_H
#define XOROSHIRO_0128_STARSTAR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "rotl.h"
#include "xoroshiro128.h"


/* stuct */
struct Xoroshiro128starstar
{
	/* data */
	uint64_t state[2];
};


/* function prototype */
void     copy_state      (       struct Xoroshiro128starstar *const dst       , const struct Xoroshiro128starstar *const src );
void     fill_state      (       struct Xoroshiro128starstar *const generator , const uint64_t src );
void     jump_state      (       struct Xoroshiro128starstar *const generator , const bool is_long_jump );
void     jump_state_core (       struct Xoroshiro128starstar *const generator , const uint64_t *const JUMP , const size_t given_size_state );
uint64_t sample_uint64   (       struct Xoroshiro128starstar *const generator );
size_t   state_size      ( const struct Xoroshiro128starstar *const generator );
void     update_state    (       struct Xoroshiro128starstar *const generator );
bool     validate_state  ( const struct Xoroshiro128starstar *const generator );

#endif /* XOROSHIRO_0128_STARSTAR_H */

/* EOF */
