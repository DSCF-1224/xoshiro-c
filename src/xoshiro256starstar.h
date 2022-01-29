#ifndef XOSHIRO_0256_STARSTAR_H
#define XOSHIRO_0256_STARSTAR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "rotl.h"
#include "xoshiro.h"
#include "xoshiro256.h"


/* struct */
struct Xoshiro256starstar
{
	/* data */
	uint64_t state[4];
};


/* function prototype */
void     copy_state      (       struct Xoshiro256starstar *const dest      , const struct Xoshiro256starstar *const src );
void     fill_state      (       struct Xoshiro256starstar *const generator , const uint64_t src );
void     jump_state      (       struct Xoshiro256starstar *const generator , const bool is_long_jump );
uint64_t sample_uint64   (       struct Xoshiro256starstar *const generator );
size_t   state_size      ( const struct Xoshiro256starstar *const generator );
void     update_state    (       struct Xoshiro256starstar *const generator );
bool     validate_state  ( const struct Xoshiro256starstar *const generator );

#endif /* XOSHIRO_0256_STARSTAR_H */

/* EOF */
