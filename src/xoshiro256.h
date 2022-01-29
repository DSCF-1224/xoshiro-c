#ifndef XOSHIRO_0256_H
#define XOSHIRO_0256_H

#include <stdint.h>
#include "rotl.h"
#include "xoshiro.h"

const static uint64_t XOSHIRO_0256_JUMP      [] = { 0x180ec6d33cfd0aba, 0xd5a61266f0c9392c, 0xa9582618e03fc9aa, 0x39abdc4529b1661c };
const static uint64_t XOSHIRO_0256_JUMP_LONG [] = { 0x76e15d3efefdcbbf, 0xc5004e441c522fb3, 0x77710069854ee241, 0x39109bb02acbe635 };


/* function prototype */
void jump_state_core_xoshiro256 ( const size_t state_size , uint64_t *const state_value , const uint64_t *const jump_parameter );
void update_state_xoshiro256    ( uint64_t *const state_value );

#endif /* XOSHIRO_0256_H */

/* EOF */
