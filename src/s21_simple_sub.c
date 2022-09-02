#include "s21_decimal.h"

int s21_simple_sub(s21_decimal var1, s21_decimal var2, s21_decimal* res) {
    int tmp = 0;
    int tmp_res = 0;
    int res_bit = 0;
    int bit1 = 0;
    int bit2 = 0;
    int raz_scale = abs(s21_get_scale(var1) - s21_get_scale(var2));

    if (s21_get_scale(var1) > s21_get_scale(var2)) {
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
    } else {
        while (s21_get_bit(var1, 95) == 0 && raz_scale > 0 && s21_get_scale(var1) < 95) {
            s21_left_shift(&var1);
            raz_scale--;
            s21_set_scale(&var1, s21_get_scale(var1) + 1);
        }

        while (raz_scale > 0 && s21_get_scale(var2) > 0) {
            s21_right_shift(&var2);
            raz_scale--;
            s21_set_scale(&var2, s21_get_scale(var2) - 1);
        }
    }
    for (int i = 0; i < 96; ++i) {
        bit1 = s21_get_bit(var1, i);
        bit2 = s21_get_bit(var2, i);
        tmp_res = bit1 - bit2 - tmp;
        tmp = tmp_res < 0 ? 1 : 0;
        res_bit = tmp ? 2 + tmp_res : tmp_res;
        s21_set_bit(res, i, res_bit);
    }

    s21_set_scale(res, s21_get_scale(var2));

    return 0;
}
