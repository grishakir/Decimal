#include "s21_decimal.h"

void s21_left_shift(s21_decimal *decl) {
    int tmp = s21_get_bit(*decl, START_MID - 1);
    int tmp_1 = s21_get_bit(*decl, START_HIGHT - 1);

    for (int i = 0; i < 3; ++i) {
        decl->bits[i] <<= 1;
    }
    s21_set_bit(decl, START_MID, tmp);
    s21_set_bit(decl, START_HIGHT, tmp_1);
    return;
}
