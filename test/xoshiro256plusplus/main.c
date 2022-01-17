#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "../../src/xoshiro256plusplus.h"

typedef struct Xoshiro256plusplus Generator;

#include "../include/constants.c"
#include "../include/fprintf_sample_unit.c"
#include "../include/fprintf_state_size.c"
#include "../include/set_sample_size.c"
#include "../include/loc_state.c"
#include "../include/set_generator_state.c"
#include "../include/fprintf_sample.c"

int main ( int const argc , const char *const argv[] )
{
	return fprintf_sample ( &argc , argv );
}
