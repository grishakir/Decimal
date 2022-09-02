#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
    s21_copy(result, value);

    if (s21_get_sign(value)) {
        s21_set_sign(result, 0);
    } else {
        s21_set_sign(result, 1);
    }
    return 0;
}
