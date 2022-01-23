// STEP.01
(*generator).workspace.lst ^= (*generator).workspace.fst;

// STEP.02.01
(*generator).state[ (*generator).address.lst ]
= rotl_uint64( (*generator).workspace.fst , 25 )
^              (*generator).workspace.lst
^            ( (*generator).workspace.lst << 27 )
;

// STEP.02.02
(*generator).state[ (*generator).address.fst ] = rotl_uint64( (*generator).workspace.lst , 36 );

// STEP.END
return;

/* EOF */
