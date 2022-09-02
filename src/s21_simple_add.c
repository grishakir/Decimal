#include "s21_decimal.h"

int s21_simple_add(s21_decimal var1, s21_decimal var2, s21_decimal* res) {
    int flag = 0;
    int tmp = 0;
    int min_summ = 0;
    int raz_scale = s21_get_scale(var1) - s21_get_scale(var2);

    while (s21_get_bit(var2, 95) == 0 && raz_scale > 0 && s21_get_scale(var2) < 95) {
        s21_left_shift(&var2);
        raz_scale--;
        s21_set_scale(&var2, s21_get_scale(var2) + 1);
    }

    while (raz_scale > 0 && s21_get_scale(var1) > 0) {
        s21_right_shift(&var1);
        raz_scale--;
        s21_set_scale(&var1, s21_get_scale(var1) - 1);
    }

    for (int i = 0; i < 96; ++i) {
        min_summ = s21_get_bit(var1, i) + s21_get_bit(var2, i) + tmp;
        tmp = min_summ / 2;
        s21_set_bit(res, i, min_summ % 2);
    }

    s21_set_scale(res, s21_get_scale(var2));

    if (tmp == 1) {
        if (s21_get_scale(var2) > 0) {
            s21_set_scale(res, s21_get_scale(var2) - 1);
            s21_right_shift(res);
            s21_set_bit(res, 95, tmp);
        } else {
            flag = 1;
        }
    }

    return flag;
}
