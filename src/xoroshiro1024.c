#include "xoroshiro1024.h"


int modify_state_address ( const int *const address_fst , const int *const iterator )
{
	return ( *iterator + *address_fst ) & 15;
}

/* EOF */
