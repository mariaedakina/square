#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

struct Koefs {

    double koef_a;
    double koef_b;
    double koef_c;
};

struct Roots {
    int nRoots;
    double first_root;
    double second_root;
};

struct Test_Date {
    int nTest;
    struct Koefs koefs;
    struct Roots roots;
    double right_x1;
    double right_x2;
    double right_nRoots;

};


enum roooots {INFINITY_ROOTS = -1, ONE_ROOT = 1, TWO_ROOTS = 2, ZERO_ROOT = 0};

const double EPS = 0.0000001;

void SolveSquare(struct Test_Date* r);
void PrintRoots(struct Roots data);
int InputCoefficients(struct Koefs* k);
int Proverka_Testami(Test_Date r);
void RUN_TESTS();


//int isNan(double);


/*int isNan(double x){
    return x != x;
} */

void SolveSquare(struct Test_Date* r) {
    assert(r != NULL);
    if (fabs(r -> koefs.koef_a) < EPS) {
        if (fabs(r -> koefs.koef_b) < EPS) {
            r->roots.nRoots = (fabs(r -> koefs.koef_c) < EPS) ? INFINITY_ROOTS : ZERO_ROOT;
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

void PrintRoots(struct Roots data) {
    assert(data.nRoots >= INFINITY_ROOTS && data.nRoots <= TWO_ROOTS);
    switch (data.nRoots) {
        case ZERO_ROOT:
            printf("No roots\n");
            break;

        case ONE_ROOT:
            printf("x = %lg\n", data.first_root);
            break;

        case TWO_ROOTS:
            printf("first_root = %lg, second_root = %lg\n", data.first_root, data.second_root);
            break;

        case INFINITY_ROOTS:
            printf("Any number\n");
            break;

        default:
            printf("error, nRoots = %d\n", data.nRoots);
    }
}

int InputCoefficients(struct Koefs* k) {
    assert(k->koef_a != NAN || k->koef_b != NAN || k->koef_c != NAN);
    printf("# enter a, b, c\n");
    char ch;
    if (scanf("%lg %lg %lg", &k -> koef_a, &k -> koef_b, &k -> koef_c) != 3) {
        printf("error? try again\n");
        return 1;

    }

    if (scanf("%c", &ch) == 1 && ch != '\n') {
        printf("error? try again\n");
        return 1;

    }

    return 0;
}

#define DO_TESTS

#ifdef DO_TESTS
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
    /*const double oshibka = NAN*/
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


#endif

int main() {
    struct Test_Date r;
    if (InputCoefficients(&r.koefs) == 1){
        return 1;
    }

    SolveSquare(&r);
    printf("koef_a=%lg koef_b=%lg koef_c=%lg\n", r.koefs.koef_a, r.koefs.koef_b, r.koefs.koef_c);
#ifdef DO_TESTS
    RUN_TESTS();
#else
    printf("no tests\n");
#endif
    PrintRoots(r.roots);

    return 0;
}
