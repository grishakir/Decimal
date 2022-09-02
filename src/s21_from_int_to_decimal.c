#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    int sign = 0;

    s21_decl_to_null(dst);

    if (src == 0) {
        dst->state = S21_NULL;
    } else {
        if (src < 0) {
            sign = 1;
            src = -src;
        }
        dst->bits[0] = src;
        s21_set_scale(dst, 0);
        s21_set_sign(dst, sign);
        dst->state = S21_NORMAL;
    }
    return 0;
}
