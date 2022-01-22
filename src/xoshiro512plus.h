#ifndef XORSHIRO_0512_PLUS_H
#define XORSHIRO_0512_PLUS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "rotl.h"
#include "xoshiro512.h"


/* stuct */
struct Xoshiro512plus
{
	/* data */
	uint64_t state[8];
};


/* function prototype */
void     copy_state      (       struct Xoshiro512plus *const dst       , const struct Xoshiro512plus *const src );
void     fill_state      (       struct Xoshiro512plus *const generator , const uint64_t src );
void     jump_state      (       struct Xoshiro512plus *const generator , const bool is_long_jump );
void     jump_state_core (       struct Xoshiro512plus *const generator , const uint64_t *const JUMP , const size_t given_size_state );
uint64_t sample_uint64   (       struct Xoshiro512plus *const generator );
size_t   state_size      ( const struct Xoshiro512plus *const generator );
void     update_state    (       struct Xoshiro512plus *const generator );
bool     validate_state  ( const struct Xoshiro512plus *const generator );

#endif /* XORSHIRO_0512_PLUS_H */

/* EOF */
