#include "s21_decimal.h"

void s21_copy(s21_decimal *dst, s21_decimal src) {
    dst->state = src.state;
    for (int i = 0; i < 4; ++i) {
        dst->bits[i] = src.bits[i];
    }
}
