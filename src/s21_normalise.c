#include "s21_decimal.h"

void s21_normalise(s21_decimal* decl) {
    for (int i = START_INFO; i <= START_INFO + 15; ++i) {
        s21_set_bit(decl, i, 0);
    }
    for (int i = START_INFO + 24; i <= START_INFO + 30; ++i) {
        s21_set_bit(decl, i, 0);
    }
    return;
}
