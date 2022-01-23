#ifndef XOROSHIRO_0128_PLUSPLUS_H
#define XOROSHIRO_0128_PLUSPLUS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "rotl.h"
#include "xoroshiro128.h"


/* stuct */
struct Xoroshiro128plusplus
{
	/* data */
	uint64_t state[2];
};


/* function prototype */
void     copy_state      (       struct Xoroshiro128plusplus *const dst       , const struct Xoroshiro128plusplus *const src );
void     fill_state      (       struct Xoroshiro128plusplus *const generator , const uint64_t src );
void     jump_state      (       struct Xoroshiro128plusplus *const generator , const bool is_long_jump );
void     jump_state_core (       struct Xoroshiro128plusplus *const generator , const uint64_t *const JUMP , const size_t given_size_state );
uint64_t sample_uint64   (       struct Xoroshiro128plusplus *const generator );
size_t   state_size      ( const struct Xoroshiro128plusplus *const generator );
void     update_state    (       struct Xoroshiro128plusplus *const generator );
bool     validate_state  ( const struct Xoroshiro128plusplus *const generator );

#endif /* XOROSHIRO_0128_PLUSPLUS_H */

/* EOF */
