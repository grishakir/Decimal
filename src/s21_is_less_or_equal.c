#include "s21_decimal.h"

int s21_is_less_or_equal(s21_decimal first, s21_decimal second) { return !s21_is_greater(first, second); }
