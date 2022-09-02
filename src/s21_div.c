#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int flag = 0;

    s21_decl_to_null(result);

    if ((value_1.state == S21_PLUS_INF && value_2.state == S21_MINUS_INF) ||
        (value_1.state == S21_MINUS_INF && value_2.state == S21_PLUS_INF)) {
        flag = 3;
        result->state = S21_NAN;
    } else if (value_1.state == S21_PLUS_INF) {
        if (!s21_get_sign(value_2)) {
            flag = 1;
            result->state = S21_PLUS_INF;
        } else {
            flag = 2;
            result->state = S21_MINUS_INF;
        }
    } else if (value_2.state == S21_PLUS_INF || value_2.state == S21_MINUS_INF) {
        flag = 0;
        result->state = S21_NULL;
    } else if (value_1.state == S21_MINUS_INF) {
        if (!s21_get_sign(value_2)) {
            flag = 2;
            result->state = S21_MINUS_INF;
        } else {
            flag = 1;
            result->state = S21_PLUS_INF;
        }
    } else if (value_1.state == S21_NAN || value_2.state == S21_NAN) {
        flag = 3;
        result->state = S21_NAN;
    } else if (value_1.state == S21_NULL) {
        flag = 0;
        result->state = S21_NULL;
    } else if (value_2.state == S21_NULL) {
        flag = 3;
        result->state = S21_NAN;
    } else if (value_1.state == S21_NORMAL && value_2.state == S21_NORMAL) {
        int sign1 = s21_get_sign(value_1);
        int sign2 = s21_get_sign(value_2);
        s21_set_sign(&value_1, 0);
        s21_set_sign(&value_2, 0);
        flag = s21_simple_div(value_1, value_2, result);
        if (sign1 == sign2 && !flag) {
            s21_set_sign(result, 0);
        } else if (!flag) {
            s21_set_sign(result, 1);
        }
        if (flag == 1) {
            result->state = S21_PLUS_INF;
        } else if (flag == 2) {
            result->state = S21_MINUS_INF;
        } else if (flag == 3) {
            result->state = S21_NORMAL;
        }
    }
    return flag;
}
