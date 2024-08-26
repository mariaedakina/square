#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "input_coefficients.h"

/**
 * @file input_coefficients.cpp
 * @brief Файл, содержащий функции для ввода коэффициентов квадратного уравнения.
 */

int InputCoefficients(struct Koefs* k) {
    assert(k != NULL);

    while (true) {
        printf("# enter numbers for a, b, c\n");

        if (scanf("%lg %lg %lg", &k->koef_a, &k->koef_b, &k->koef_c) == 3) {
            if (getchar() != '\n') {
                printf("error? try again\n");

                while (getchar() != '\n' && getchar() != EOF);
                continue;
            }
            break;
        } else {
            printf("error? try again\n");
            while (getchar() != '\n');
        }
    }

    return 0;
}
