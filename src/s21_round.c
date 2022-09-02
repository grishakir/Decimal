#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
    int flag = 0;

    s21_decimal one = {{1, 0, 0, 0}, 1};
    s21_copy(result, value);
    if (value.state == S21_PLUS_INF || value.state == S21_MINUS_INF || value.state == S21_NAN ||
        value.state == S21_NULL) {
        flag = 1;
    } else {
        if (s21_get_scale(value)) {
            if (s21_get_bit(value, s21_get_scale(value) - 1)) {
                if (s21_get_sign(value)) {
                    s21_sub(value, one, result);
                } else {
                    s21_add(value, one, result);
                }
            }
            for (int i = 0; i < s21_get_scale(value); ++i) s21_right_shift(result);
            s21_set_scale(result, 0);
        }
    }
    return flag;
}
