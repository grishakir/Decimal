#include "s21_decimal.h"

int s21_is_greater(s21_decimal first, s21_decimal second) {
    int is_greater = 0;
    int tmp_raz = 0;
    int bit_1 = 0;
    int bit_2 = 0;
    int first_flag = 1;
    int end_loop_flag = 0;
    s21_decimal *one, *two;

    if (second.state == S21_PLUS_INF || first.state == S21_MINUS_INF || first.state == S21_NAN ||
        second.state == S21_NAN) {
        is_greater = 0;
    } else if (first.state == S21_NULL && !s21_get_sign(second)) {
        is_greater = 0;
    } else if (s21_get_sign(first) == 1 && s21_get_sign(second) == 0) {
        is_greater = 0;
    } else if (s21_get_sign(first) == 0 && s21_get_sign(second) == 1) {
        is_greater = 1;
    } else {
        is_greater = 0;
        if (s21_get_scale(first) <= s21_get_scale(second)) {
            one = &first;
            two = &second;
        } else {
            first_flag = 0;
            one = &second;
            two = &first;
        }
        tmp_raz = s21_get_scale(*one) - s21_get_scale(*two);

        for (int i = 95; i >= tmp_raz && !end_loop_flag; --i) {
            if (i < 0) {
                bit_1 = 0;
            } else {
                bit_1 = s21_get_bit(*one, i);
            }
            if (i - tmp_raz > 95) {
                bit_2 = 0;
            } else {
                bit_2 = s21_get_bit(*two, i - tmp_raz);
            }
            if (bit_1 > bit_2) {
                if (first_flag) {
                    is_greater = 1;
                } else {
                    is_greater = 0;
                }
                end_loop_flag = 1;
            } else if (bit_1 < bit_2) {
                if (first_flag) {
                    is_greater = 0;
                } else {
                    is_greater = 1;
                }
                end_loop_flag = 1;
            }
        }

        if (s21_get_sign(first) && s21_get_sign(second)) {
            is_greater = !is_greater;
        }
    }
    return is_greater;
}
