#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/xoroshiro128plus.c"
#include "../include/fprintf_sample_64bit.c"

int main ( int const argc , char const *argv[] )
{
	return fprintf_sample( &argc , argv );
}
