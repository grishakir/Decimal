#include "s21_decimal.h"

int s21_simple_mul(s21_decimal value1, s21_decimal value2, s21_decimal *result) {
    int flag = 0;
    s21_decimal tmp;
    int res_scale = s21_get_scale(value1) + s21_get_scale(value2);
    s21_decl_to_null(result);
    s21_set_scale(result, res_scale);
    result->state = S21_NORMAL;

    for (int i = 0; i < 96 && !flag; ++i) {
        if (s21_get_bit(value2, i)) {
            s21_copy(&tmp, value1);
            s21_set_sign(&tmp, 0);
            s21_set_scale(&tmp, res_scale);
            for (int j = 0; j < i && !flag; ++j) {
                if (!s21_get_bit(tmp, 95)) {
                    s21_left_shift(&tmp);
                } else if (s21_get_scale(tmp) > 0) {
                    s21_set_scale(&tmp, s21_get_scale(tmp) - 1);
                } else {
                    if (s21_get_sign(value1) == s21_get_sign(value2)) {
                        flag = 1;
                    } else {
                        flag = 2;
                    }
                }
            }
            flag = s21_add(tmp, *result, result);
        }
    }
    return flag;
}
