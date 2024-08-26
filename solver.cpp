#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "solver.h"

/**
 * @file solver.cpp
 * @brief Файл, содержащий функции для решения квадратных уравнений.
 */

void SolveSquare(struct Test_Date* r) {
    assert(r != NULL);

    if (fabs(r->koefs.koef_a) < EPS) {
        if (fabs(r->koefs.koef_b) < EPS) {
            r->roots.nRoots = (fabs(r->koefs.koef_c) < EPS) ? INFINITY_ROOTS : ZERO_ROOT;
            return;
        } else {
            r->roots.first_root = -r->koefs.koef_c / r->koefs.koef_b;
            r->roots.nRoots = ONE_ROOT;
            return;
        }
    } else {
        double discriminant = (r->koefs.koef_b * r->koefs.koef_b - 4 * r->koefs.koef_a * r->koefs.koef_c);
        if (fabs(discriminant) < EPS) {
            r->roots.first_root = r->roots.second_root = -r->koefs.koef_b / (2 * r->koefs.koef_a);
            r->roots.nRoots = ONE_ROOT;
            return;
        } else if (discriminant > 0) {
            r->roots.first_root = (-r->koefs.koef_b - sqrt(discriminant)) / (2 * r->koefs.koef_a);
            r->roots.second_root = (-r->koefs.koef_b + sqrt(discriminant)) / (2 * r->koefs.koef_a);
            r->roots.nRoots = TWO_ROOTS;
            return;
        }
    }

    r->roots.nRoots = ZERO_ROOT;
}




