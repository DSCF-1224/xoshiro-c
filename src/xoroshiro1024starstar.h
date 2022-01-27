#ifndef XOROSHIRO_1024_STARSTAR_H
#define XOROSHIRO_1024_STARSTAR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "rotl.h"
#include "xoroshiro1024.h"


/* struct */
struct Xoroshiro1024starstar
{
	/* data */
	struct Xoroshiro1024_State     state;
	struct Xoroshiro1024_Address   address;
	struct Xoroshiro1024_Workspace workspace;
};


/* function prototype */
void     copy_state           (       struct Xoroshiro1024starstar *const dst       , const struct Xoroshiro1024starstar *const src );
void     fill_state           (       struct Xoroshiro1024starstar *const generator , const uint64_t src );
void     initialize_generator (       struct Xoroshiro1024starstar *const generator , const int address );
void     jump_state           (       struct Xoroshiro1024starstar *const generator , const bool is_long_jump );
uint64_t sample_uint64        (       struct Xoroshiro1024starstar *const generator );
size_t   state_size           ( const struct Xoroshiro1024starstar *const generator );
void     update_state         (       struct Xoroshiro1024starstar *const generator );
void     update_state_pre     (       struct Xoroshiro1024starstar *const generator );
void     update_state_pst     (       struct Xoroshiro1024starstar *const generator );
bool     validate_state       ( const struct Xoroshiro1024starstar *const generator );

#endif /* XOROSHIRO_1024_STARSTAR_H */

/* EOF */
