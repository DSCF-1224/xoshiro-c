// STEP.01
// initialize the return value of this function
bool validity = false;

// STEP.02
// check the given state
for ( size_t itr_stat = 0; itr_stat < state_size(generator); ++itr_stat )
{
	validity = validity | ( (*generator).state[itr_stat] != 0 );
}

// STEP.END
return validity;

/* EOF */
