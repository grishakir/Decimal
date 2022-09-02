#include "s21_decimal.h"

int s21_get_scale(s21_decimal decl) {
    int scale = 0;
    for (int i = START_INFO + 23; i >= START_INFO + 16; --i) {
        scale <<= 1;
        scale |= s21_get_bit(decl, i);
    }
    return scale;
}
