#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"

#define START_LOW 0
#define START_MID 32
#define START_HIGHT 64
#define START_INFO 96

typedef enum { S21_NULL, S21_NORMAL, S21_PLUS_INF, S21_MINUS_INF, S21_NAN, S21_DOP } State;

typedef struct s21_decimal {
    unsigned int bits[4];
    State state;
} s21_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

void print_dec(s21_decimal decl);
void print_float(float decl);
void s21_set_bit(s21_decimal *decl, int index, int bit);
int s21_get_bit(s21_decimal decl, int index);
void s21_set_sign(s21_decimal *decl, int sign);
int s21_get_sign(s21_decimal decl);
int s21_get_scale(s21_decimal decl);
void s21_set_scale(s21_decimal *decl, int scale);
void s21_normalise(s21_decimal *decil);
void s21_decl_to_null(s21_decimal *decl);
void s21_right_shift(s21_decimal *decl);
void s21_left_shift(s21_decimal *decl);
int s21_simple_add(s21_decimal var1, s21_decimal var2, s21_decimal *res);
int s21_simple_sub(s21_decimal var1, s21_decimal var2, s21_decimal *result);
void s21_copy(s21_decimal *dst, s21_decimal src);
int s21_simple_mul(s21_decimal value1, s21_decimal value2, s21_decimal *result);
int s21_simple_div(s21_decimal value1, s21_decimal value2, s21_decimal *result);
int s21_simple_mod(s21_decimal value1, s21_decimal value2, s21_decimal *result);

#endif  // SRC_S21_DECIMAL_H_
