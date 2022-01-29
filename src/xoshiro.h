#ifndef XOSHIRO_H
#define XOSHIRO_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

void copy_state_xoshiro      ( const size_t state_size , uint64_t *const dest , const uint64_t *const src );
void fill_state_xoshiro      ( const size_t state_size , uint64_t *const state_value , const uint64_t source );
bool validate_state_xoshiro  ( const size_t state_size , const uint64_t *const state_value );

#endif /* XOSHIRO_H */

/* EOF */
