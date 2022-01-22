// STEP.01
	const uint64_t workspace = ( (*generator).state[1] << 17 );

// STEP.02
(*generator).state[2] ^= (*generator).state[0];
(*generator).state[3] ^= (*generator).state[1];
(*generator).state[1] ^= (*generator).state[2];
(*generator).state[0] ^= (*generator).state[3];

// STEP.03
(*generator).state[2] ^= workspace;

// STEP.04
(*generator).state[3] = rotl_uint64( (*generator).state[3] , 45 );

// STEP.END
return;

/* EOF */
