#ifndef XOSHIRO_0256_PLUSPLUS_H
#define XOSHIRO_0256_PLUSPLUS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "rotl.h"
#include "xoshiro256.h"


/* struct */
struct Xoshiro256plusplus
{
	/* data */
	uint64_t state[4];
};


/* function prototype */
void     copy_state      (       struct Xoshiro256plusplus *const dst       , const struct Xoshiro256plusplus *const src );
void     fill_state      (       struct Xoshiro256plusplus *const generator , const uint64_t src );
void     jump_state      (       struct Xoshiro256plusplus *const generator , const bool is_long_jump );
void     jump_state_core (       struct Xoshiro256plusplus *const generator , const uint64_t *const JUMP , const size_t given_size_state );
uint64_t sample_uint64   (       struct Xoshiro256plusplus *const generator );
size_t   state_size      ( const struct Xoshiro256plusplus *const generator );
void     update_state    (       struct Xoshiro256plusplus *const generator );
bool     validate_state  ( const struct Xoshiro256plusplus *const generator );

#endif /* XOSHIRO_0256_PLUSPLUS_H */

/* EOF */
