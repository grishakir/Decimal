#include "s21_decimal.h"

int s21_get_bit(s21_decimal decl, int index) {
    int num_int = index / 32;
    int num_bit = index % 32;
    return (decl.bits[num_int] & (1u << num_bit)) >> num_bit;
}
