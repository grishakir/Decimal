#include "s21_decimal.h"

int s21_get_sign(s21_decimal decl) { return s21_get_bit(decl, 127); }
