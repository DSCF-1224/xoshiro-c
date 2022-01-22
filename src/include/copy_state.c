// STEP.01
for (size_t itr_stat = 0; itr_stat < state_size(dst); ++itr_stat)
{
	(*dst).state[itr_stat] = (*src).state[itr_stat];
}

// STEP.END
return;

/* EOF */
