#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "printer.h"
#include "solver.h"


/**
 * @file printer.cpp
 * @brief Файл, содержащий функции для вывода корней квадратного уравнения.
 */

/**
 * @brief Проверяет, является ли корень близким к нулю и возвращает его абсолютное значение.
 *
 * Функция проверяет, является ли переданный корень близким к нулю (в пределах EPS).
 * Если да, то возвращает 0, иначе возвращает сам корень.
 *
 * @param root Корень, который нужно проверить.
 * @return Если корень сравним с нулем в рамках погрешности, возвращает 0; иначе возвращает сам корень.
 */


double CheckMinus(double root);

double CheckMinus(double root) {
    return (fabs(root) < EPS) ? fabs(root) : root;
}


void PrintRoots(struct Roots data) {
    assert(data.nRoots >= INFINITY_ROOTS && data.nRoots <= TWO_ROOTS);

    switch (data.nRoots) {
        case ZERO_ROOT:
            printf("No roots\n");
            break;

        case ONE_ROOT:
            printf("x = %lg\n", CheckMinus(data.first_root));
            break;

        case TWO_ROOTS:
            printf("first_root = %lg, second_root = %lg\n", CheckMinus(data.first_root), CheckMinus(data.second_root));
            break;

        case INFINITY_ROOTS:
            printf("Any number\n");
            break;

        default:
            printf("error, nRoots = %d\n", data.nRoots);
    }
}

