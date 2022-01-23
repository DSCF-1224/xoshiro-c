#ifndef XOROSHIRO_1024_STAR_H
#define XOROSHIRO_1024_STAR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "rotl.h"
#include "xoroshiro1024.h"


/* struct */
struct Xoroshiro1024star_Address
{
	/* data */
	int fst;
	int lst;
};

struct Xoroshiro1024star_Workspace
{
	/* data */
	uint64_t fst;
	uint64_t lst;
};

struct Xoroshiro1024star
{
	/* data */
	uint64_t                           state[16];
	struct Xoroshiro1024star_Address   address;
	struct Xoroshiro1024star_Workspace workspace;
};


/* function prototype */
void     copy_state           (       struct Xoroshiro1024star *const dst       , const struct Xoroshiro1024star *const src );
void     fill_state           (       struct Xoroshiro1024star *const generator , const uint64_t src );
void     initialize_generator (       struct Xoroshiro1024star *const generator );
void     jump_state           (       struct Xoroshiro1024star *const generator , const bool is_long_jump );
void     jump_state_core      (       struct Xoroshiro1024star *const generator , const uint64_t *const JUMP , const size_t given_size_state );
uint64_t sample_uint64        (       struct Xoroshiro1024star *const generator );
size_t   state_size           ( const struct Xoroshiro1024star *const generator );
void     update_state         (       struct Xoroshiro1024star *const generator );
void     update_state_pre     (       struct Xoroshiro1024star *const generator );
void     update_state_pst     (       struct Xoroshiro1024star *const generator );
bool     validate_state       ( const struct Xoroshiro1024star *const generator );

#endif /* XOROSHIRO_1024_STAR_H */

/* EOF */
