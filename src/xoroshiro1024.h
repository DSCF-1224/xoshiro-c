#ifndef XOROSHIRO_1024_H
#define XOROSHIRO_1024_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "rotl.h"

#define STATE_SIZE_XOROSHIRO_1024 16

const static uint64_t XOROSHIRO_1024_JUMP [] =
	{
		0x931197d8e3177f17,
		0xb59422e0b9138c5f,
		0xf06a6afb49d668bb,
		0xacb8a6412c8a1401,
		0x12304ec85f0b3468,
		0xb7dfe7079209891e,
		0x405b7eec77d9eb14,
		0x34ead68280c44e4a,
		0xe0e4ba3e0ac9e366,
		0x8f46eda8348905b7,
		0x328bf4dbad90d6ff,
		0xc8fd6fb31c9effc3,
		0xe899d452d4b67652,
		0x45f387286ade3205,
		0x03864f454a8920bd,
		0xa68fa28725b1b384
	};

const static uint64_t XOROSHIRO_1024_JUMP_LONG [] = 
	{
		0x7374156360bbf00f,
		0x4630c2efa3b3c1f6,
		0x6654183a892786b1,
		0x94f7bfcbfb0f1661,
		0x27d8243d3d13eb2d,
		0x9701730f3dfb300f,
		0x2f293baae6f604ad,
		0xa661831cb60cd8b6,
		0x68280c77d9fe008c,
		0x50554160f5ba9459,
		0x2fc20b17ec7b2a9a,
		0x49189bbdc8ec9f8f,
		0x92a65bca41852cc1,
		0xf46820dd0509c12a,
		0x52b00c35fbf92185,
		0x1e5b3b7f589e03c1
	};


/* struct */
struct Xoroshiro1024_Address
{
	/* data */
	int fst;
	int lst;
};


struct Xoroshiro1024_State
{
	/* data */
	uint64_t value[STATE_SIZE_XOROSHIRO_1024];
};


struct Xoroshiro1024_Workspace
{
	/* data */
	uint64_t fst;
	uint64_t lst;
};


/* function prototype */
int    modify_state_address             ( const struct Xoroshiro1024_Address *const address , const int iterator );
void   copy_state_value_xoroshiro1024   ( struct Xoroshiro1024_State *const dst , const struct Xoroshiro1024_State *const src );
void   fill_state_value_xoroshiro1024   ( struct Xoroshiro1024_State *const generator , const uint64_t src );
void   initialize_address_xoroshiro1024 ( struct Xoroshiro1024_Address *const instance , const int address );
void   jump_state_core_xoroshiro1024    ( struct Xoroshiro1024_Address *const address , struct Xoroshiro1024_State *const state , struct Xoroshiro1024_Workspace *const workspace , const uint64_t *const JUMP );
size_t state_size_xoroshiro1024         ( const struct Xoroshiro1024_State *const state );
void   update_state_pre_xoroshiro1024   ( struct Xoroshiro1024_Address *const address , struct Xoroshiro1024_State *const state , struct Xoroshiro1024_Workspace *const workspace );
void   update_state_pst_xoroshiro1024   ( struct Xoroshiro1024_Address *const address , struct Xoroshiro1024_State *const state , struct Xoroshiro1024_Workspace *const workspace );
bool   validate_state_xoroshiro1024     ( const struct Xoroshiro1024_State *const state );

#endif /* XOROSHIRO_1024_H */

/* EOF */
