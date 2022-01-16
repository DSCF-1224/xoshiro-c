#include "rotl.h"


uint32_t rotl_uint32 ( const uint32_t x , const int shift )
{
	return (x << shift) | (x >> (32 - shift));
}


uint64_t rotl_uint64 ( const uint64_t x , const int shift )
{
	return (x << shift) | (x >> (64 - shift));
}

/* EOF */
