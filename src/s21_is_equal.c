#include "s21_decimal.h"

int s21_is_equal(s21_decimal first, s21_decimal second) {
    int is_equal = 1;
    s21_decimal *one;
    s21_decimal *two;

    int tmp_raz = 0;
    int bit_1 = 0;
    int bit_2 = 0;
    if (first.state != second.state) {
        is_equal = 0;
    } else {
        is_equal = 1;
        if (s21_get_scale(first) <= s21_get_scale(second)) {
            one = &first;
            two = &second;
        } else {
            one = &second;
            two = &first;
        }
        tmp_raz = s21_get_scale(*one) - s21_get_scale(*two);

        for (int i = 95; i >= tmp_raz; --i) {
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
            if (bit_1 != bit_2) {
                is_equal = 0;
                break;
            }
        }
    }
    return is_equal;
}
