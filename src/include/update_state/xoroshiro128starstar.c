// STEP.01
copy_state( &workspace , generator );

// STEP.02
workspace.state[1] ^= workspace.state[0];

// STEP.02.02
(*generator).state[0]
= rotl_uint64( workspace.state[0] , 24 )
^              workspace.state[1]
^            ( workspace.state[1] << 16 )
;

// STEP.02.03
(*generator).state[1] = rotl_uint64( workspace.state[1] , 37 );

// STEP.END
return;

/* EOF */
