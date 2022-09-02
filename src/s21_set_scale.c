#include "s21_decimal.h"

void s21_set_scale(s21_decimal* decl, int scale) {
    for (int i = START_INFO + 16; i < START_INFO + 23; ++i) {
        s21_set_bit(decl, i, scale & 1);
        scale >>= 1;
    }
}
