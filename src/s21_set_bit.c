#include "s21_decimal.h"

void s21_set_bit(s21_decimal* decl, int index, int bit) {
    int num_int = index / 32;
    int num_bit = index % 32;
    if (bit == 1) {
        decl->bits[num_int] |= (1u << num_bit);
    } else {
        decl->bits[num_int] &= (~((1u) << num_bit));
    }
    return;
}
