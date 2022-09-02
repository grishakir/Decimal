#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
    int flag = 0;

    if (value.state == S21_PLUS_INF || value.state == S21_MINUS_INF || value.state == S21_NAN) {
        flag = 1;
    } else {
        s21_copy(result, value);

        for (int i = 0; i < s21_get_scale(value); ++i) {
            s21_right_shift(result);
        }
        s21_set_scale(result, 0);
    }
    return flag;
}
