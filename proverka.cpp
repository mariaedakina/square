#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "proverka.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "proverka.h"


/**
 * @file proverka.cpp
 * @brief Файл, содержащий функции для проверки корректности решения квадратных уравнений.
 */


int Proverka_Testami(Test_Date r)  {
    SolveSquare(&r);

    int nRoots = r.roots.nRoots;
    double first_root = r.roots.first_root;
    double second_root = r.roots.second_root;

    if (fabs(r.right_nRoots-2) < EPS){
        if (fabs(nRoots - r.right_nRoots) > EPS || fabs(first_root - r.right_x1) > EPS  || fabs(second_root - r.right_x2) > EPS){
            printf("error test %d, koef_a = %lg, koef_b = %lg, koef_c = %lg, first_root = %lg, second_root = %lg, nRoots = %d\n"
            "Expected: first_root = %lg, second_root = %lg, nRoots = %lg\n", r.nTest, r.koefs.koef_a, r.koefs.koef_b,
            r.koefs.koef_c, first_root, second_root, nRoots, r.right_x1, r.right_x2, r.right_nRoots);
            return 1;
        }
    }

    else if (fabs(r.right_nRoots-1) < EPS){
        if (fabs(nRoots - r.right_nRoots) > EPS || fabs(first_root - r.right_x1) > EPS) {
            printf("error test %d, koef_a = %lg, koef_b = %lg, koef_c = %lg, first_root = %lg, nRoots = %d"
            "Expected: first_root = %lg, nRoots = %lg\n" , r.nTest, r.koefs.koef_a, r.koefs.koef_b, r.koefs.koef_c, first_root, nRoots, r.right_x1, r.right_nRoots);
            return 1;
        }
    }

    else if (fabs(nRoots - r.right_nRoots) < EPS) {
        return 0;
    }
    else if (fabs(r.right_nRoots - INFINITY_ROOTS) < EPS){
        printf("error test %d, koef_a = %lg, koef_b = %lg, koef_c = % lg, infinity roots"
               "Expected: infinity\n", r.nTest, r.koefs.koef_a, r.koefs.koef_b, r.koefs.koef_c);
    }
    return 0;
}

void RUN_TESTS() {
    const int nTests = 7;
    struct Test_Date tests[] = {
    // n_Test    koefs        x1         x2          nRoots
        {0,   {1, 0, -4},    -2,         2,         TWO_ROOTS},
        {1,   {1, -2, -3},   -1,         3,         TWO_ROOTS},
        {2,   {0, 0, -4},   (int) NAN,   NAN,       ZERO_ROOT},
        {3,   {0, 0, 0},    (int) NAN,   NAN,  INFINITY_ROOTS},
        {4,   {1, -4, -5},   -1,         5,         TWO_ROOTS},
        {5,   {1, -2, 1},     1,         NAN,        ONE_ROOT},
        {6,   {0.25, -5, 0},  0,         20,        TWO_ROOTS},
        {7,   {1, -5, 9},   (int) NAN,   NAN,       ZERO_ROOT}
    };

    for (int i = 0; i < nTests; i++) {
        if (Proverka_Testami(tests[i]) == 1) {
            printf("Test %d failed.\n", tests[i].nTest);
        }
    }
}

