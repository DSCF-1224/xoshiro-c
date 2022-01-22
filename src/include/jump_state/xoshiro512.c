// STEP.01
if   (is_long_jump) jump_state_core( generator , XOSHIRO_0512_JUMP_LONG , state_size(generator) );
else                jump_state_core( generator , XOSHIRO_0512_JUMP      , state_size(generator) );

// STEP.END
return;

/* EOF */
