// STEP.01
	const uint64_t workspace = ( (*generator).state[1] << 11 );

// STEP.02
(*generator).state[2] ^= (*generator).state[0];
(*generator).state[5] ^= (*generator).state[1];
(*generator).state[1] ^= (*generator).state[2];
(*generator).state[7] ^= (*generator).state[3];
(*generator).state[3] ^= (*generator).state[4];
(*generator).state[4] ^= (*generator).state[5];
(*generator).state[0] ^= (*generator).state[6];
(*generator).state[6] ^= (*generator).state[7];

// STEP.03
(*generator).state[6] ^= workspace;

// STEP.04
(*generator).state[7] = rotl_uint64( (*generator).state[7] , 21 );

// STEP.END
return;

/* EOF */
