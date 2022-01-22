// STEP.01
for (size_t itr_stat = 0; itr_stat < state_size(generator); ++itr_stat)
{
	(*generator).state[itr_stat] = src;
}

// STEP.END
return;

/* EOF */
