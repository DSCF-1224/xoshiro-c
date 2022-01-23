#ifndef XOSHIRO_0512_PLUSPLUS_H
#define XOSHIRO_0512_PLUSPLUS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "rotl.h"
#include "xoshiro512.h"


/* struct */
struct Xoshiro512plusplus
{
	/* data */
	uint64_t state[8];
};


/* function prototype */
void     copy_state      (       struct Xoshiro512plusplus *const dst       , const struct Xoshiro512plusplus *const src );
void     fill_state      (       struct Xoshiro512plusplus *const generator , const uint64_t src );
void     jump_state      (       struct Xoshiro512plusplus *const generator , const bool is_long_jump );
void     jump_state_core (       struct Xoshiro512plusplus *const generator , const uint64_t *const JUMP , const size_t given_size_state );
uint64_t sample_uint64   (       struct Xoshiro512plusplus *const generator );
size_t   state_size      ( const struct Xoshiro512plusplus *const generator );
void     update_state    (       struct Xoshiro512plusplus *const generator );
bool     validate_state  ( const struct Xoshiro512plusplus *const generator );

#endif /* XOSHIRO_0512_PLUSPLUS_H */

/* EOF */
