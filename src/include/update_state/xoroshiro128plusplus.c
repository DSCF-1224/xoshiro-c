// STEP.01
copy_state( &workspace , generator );

// STEP.02
workspace.state[1] ^= workspace.state[0];

// STEP.02.02
(*generator).state[0]
= rotl_uint64( workspace.state[0] , 49 )
^              workspace.state[1]
^            ( workspace.state[1] << 21 )
;

// STEP.02.03
(*generator).state[1] = rotl_uint64( workspace.state[1] , 28 );

// STEP.END
return;

/* EOF */
