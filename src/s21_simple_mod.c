#include "s21_decimal.h"

int s21_simple_mod(s21_decimal value1, s21_decimal value2, s21_decimal *result) {
    int flag = 0;
    s21_decimal one = {{1, 0, 0, 0}, S21_NORMAL};
    s21_decl_to_null(result);
    result->state = S21_NORMAL;
    s21_decimal big_val_2, tmp;
    tmp.state = S21_NORMAL;
    tmp.bits[0] = 0;
    tmp.bits[1] = 0;
    tmp.bits[2] = 0;
    tmp.bits[3] = 0;

    for (int i = 94; i >= 0; --i) {
        s21_set_bit(&tmp, i + 1, 0);
        s21_set_bit(&tmp, i, 1);
        flag = s21_mul(value2, tmp, &big_val_2);
        while (s21_is_greater_or_equal(value1, big_val_2) && !flag) {
            flag = s21_add(*result, tmp, result);
            if (!flag) {
                flag = s21_sub(value1, big_val_2, &value1);
            }
        }
        flag = 0;
    }

    while (s21_is_greater_or_equal(value1, value2) && !flag) {
        flag = s21_add(*result, one, result);
        if (!flag) {
            flag = s21_sub(value1, value2, &value1);
        }
    }
    s21_copy(result, value1);

    return flag;
}
