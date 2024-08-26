#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "input_coefficients.h"

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
    assert(k != NULL); // Проверка на NULL
    printf("# enter a, b, c\n");
    char ch;

    // Ввод коэффициентов
    if (scanf("%lg %lg %lg", &k->koef_a, &k->koef_b, &k->koef_c) != 3) {
        printf("error? try again\n");
        return 1; // Ошибка ввода
    }

    // Проверка на наличие лишних символов после ввода
    if (scanf("%c", &ch) == 1 && ch != '\n') {
        printf("error? try again\n");
        return 1; // Ошибка ввода
    }

    return 0; // Успешный ввод
}
