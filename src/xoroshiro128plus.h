#ifndef XOROSHIRO_0128_PLUS_H
#define XOROSHIRO_0128_PLUS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "rotl.h"
#include "xoroshiro128.h"


/* struct */
struct Xoroshiro128plus
{
	/* data */
	uint64_t state[2];
};


/* function prototype */
void     copy_state      (       struct Xoroshiro128plus *const dst       , const struct Xoroshiro128plus *const src );
void     fill_state      (       struct Xoroshiro128plus *const generator , const uint64_t src );
void     jump_state      (       struct Xoroshiro128plus *const generator , const bool is_long_jump );
void     jump_state_core (       struct Xoroshiro128plus *const generator , const uint64_t *const JUMP , const size_t given_size_state );
uint64_t sample_uint64   (       struct Xoroshiro128plus *const generator );
size_t   state_size      ( const struct Xoroshiro128plus *const generator );
void     update_state    (       struct Xoroshiro128plus *const generator );
bool     validate_state  ( const struct Xoroshiro128plus *const generator );

#endif /* XOROSHIRO_0128_PLUS_H */

/* EOF */
