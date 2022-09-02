#include "s21_decimal.h"

union float_bits {
    uint32_t bits;
    float num_f;
};

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    union float_bits src_bits;
    src_bits.num_f = src;
    int scale = 0;
    int return_val = 0;
    s21_decl_to_null(dst);
    if (fabs(src) < 1e-28) {
        return_val = 1;
        dst->state = S21_NULL;
    } else if (src > 79228162514264337593543950335.0) {
        return_val = 1;
        dst->state = S21_PLUS_INF;
    } else if (src < -79228162514264337593543950335.0) {
        return_val = 1;
        dst->state = S21_MINUS_INF;
    } else if (__builtin_isnan(src)) {
        return_val = 1;
        dst->state = S21_NAN;
    } else {
        s21_set_sign(dst, (src_bits.bits & (1u << 31)) >> 31);
        s21_set_bit(dst, 23, 1);
        for (int i = 22; i >= 0; --i) {
            s21_set_bit(dst, i, (src_bits.bits & (1u << i)) >> i);
        }

        for (int i = 30; i >= 23; --i) {
            scale <<= 1;
            scale |= (src_bits.bits & (1u << i)) >> i;
        }
        scale -= 127;
        scale = 23 - scale;
        while (scale < 0) {
            s21_left_shift(dst);
            scale++;
        }
        s21_set_scale(dst, scale);
        dst->state = S21_NORMAL;
    }
    return return_val;
}
