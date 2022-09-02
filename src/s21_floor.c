#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
    int flag = 0;
    int flag_ne_oshibki = 0;
    s21_decimal one = {{1, 0, 0, 0}, S21_NORMAL};

    if (value.state == S21_PLUS_INF || value.state == S21_MINUS_INF || value.state == S21_NAN) {
        flag = 1;
    } else if (!s21_get_sign(value)) {
        flag = s21_truncate(value, result);
    } else {
        s21_copy(result, value);
        for (int i = 0; i < s21_get_scale(value); ++i) {
            flag_ne_oshibki |= s21_get_bit(value, i);
        }
        if (flag_ne_oshibki) {
            flag = s21_sub(value, one, result);
        }
        flag = s21_truncate(*result, result);
    }
    return flag;
}
