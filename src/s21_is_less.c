#include "s21_decimal.h"

int s21_is_less(s21_decimal first, s21_decimal second) {
    return !s21_is_greater(first, second) && s21_is_not_equal(first, second);
}
