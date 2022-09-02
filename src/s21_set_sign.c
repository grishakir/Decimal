#include "s21_decimal.h"

void s21_set_sign(s21_decimal *decl, int sign) {
    s21_set_bit(decl, 127, sign);
    return;
}
