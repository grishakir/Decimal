#include "./tests/s21_decimal_tst.h"

int main(void) {
    run_tests();
    return 0;
}

void run_testcase(Suite *testcase) {
    static int counter_testcase = 1;
    if (counter_testcase > 1) counter_testcase++;
    SRunner *sr = srunner_create(testcase);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
}

void run_tests(void) {
    Suite *list_case[] = {
        suite_s21_from_int_to_decimal_ste(),
        suite_s21_from_float_to_decimal_ste(),
        suite_s21_from_decimal_to_float_ste(),
        suite_s21_from_decimal_to_int_ste(),
        suite_s21_is_greater_ste(),
        suite_s21_is_equal_ste(),
        suite_s21_is_not_equal_ste(),
        suite_s21_is_greater_or_equal_ste(),
        suite_s21_is_less_ste(),
        suite_s21_is_less_or_equal_ste(),
        suite_s21_add_ste(),
        suite_s21_sub_ste(),
        suite_s21_round_ste(),
        suite_s21_mul_ste(),
        suite_s21_div_ste(),
        suite_s21_mod_ste(),
        suite_s21_truncate_ste(),
        suite_s21_floor_ste(),
        NULL,
    };

    for (Suite **current_testcase = list_case; *current_testcase; ++current_testcase) {
        run_testcase(*current_testcase);
    }
}

float Rand_R(float a, float b) {
    float m = (float)rand() / RAND_MAX;
    float num = a + m * (b - a);
    return num;
}
