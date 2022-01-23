// STEP.01
(*generator).address.lst =   (*generator).address.fst;
(*generator).address.fst = ( (*generator).address.fst + 1 ) & 15;

// STEP.02
(*generator).workspace.fst = (*generator).state[ (*generator).address.fst ];
(*generator).workspace.lst = (*generator).state[ (*generator).address.lst ];

// STEP.END
return;

/* EOF */
