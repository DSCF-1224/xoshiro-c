#ifndef XOSHIRO_0512_STARSTAR_H
#define XOSHIRO_0512_STARSTAR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "rotl.h"
#include "xoshiro512.h"


/* struct */
struct Xoshiro512starstar
{
	/* data */
	uint64_t state[8];
};


/* function prototype */
void     copy_state      (       struct Xoshiro512starstar *const dst       , const struct Xoshiro512starstar *const src );
void     fill_state      (       struct Xoshiro512starstar *const generator , const uint64_t src );
void     jump_state      (       struct Xoshiro512starstar *const generator , const bool is_long_jump );
void     jump_state_core (       struct Xoshiro512starstar *const generator , const uint64_t *const JUMP , const size_t given_size_state );
uint64_t sample_uint64   (       struct Xoshiro512starstar *const generator );
size_t   state_size      ( const struct Xoshiro512starstar *const generator );
void     update_state    (       struct Xoshiro512starstar *const generator );
bool     validate_state  ( const struct Xoshiro512starstar *const generator );

#endif /* XOSHIRO_0512_STARSTAR_H */

/* EOF */
