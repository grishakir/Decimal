#include "s21_decimal.h"

union float_bits {
    uint32_t bits;
    float num_f;
};

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    int position = 0;
    union float_bits f_num;
    f_num.bits = 0;
    int count = 22;
    int biter = 0;

    if (src.state == S21_NULL || (!src.bits[0] && !src.bits[1] && !src.bits[2])) {
        *dst = 0;
    } else if (src.state == S21_PLUS_INF) {
        *dst = +1.0 / 0.0;
    } else if (src.state == S21_MINUS_INF) {
        *dst = -1.0 / 0.0;
    } else if (src.state == S21_NAN) {
        *dst = 0.0 / 0.0;
    } else if (src.state == S21_NORMAL) {
        for (int i = 95; i >= 0 && !position; --i) {
            if (s21_get_bit(src, i)) {
                position = i;
            }
        }
        for (int j = position - 1; j >= position - 1 - 22; --j) {
            if (j < 0) {
                biter = 0;
            } else {
                biter = s21_get_bit(src, j);
            }
            f_num.bits |= (biter << count);
            count--;
        }
        position = position - s21_get_scale(src) + 127;

        for (int k = 23; k <= 30; ++k) {
            f_num.bits |= ((position & 1) << k);
            position >>= 1;
        }
        f_num.bits |= ((s21_get_sign(src)) << 31);
        *dst = f_num.num_f;
    }
    return 0;
}
