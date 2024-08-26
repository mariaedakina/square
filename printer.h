#ifndef PRINTER_H
#define PRINTER_H

#include "solver.h"

/**
 * @file printer.h
 * @brief Заголовочный файл для вывода результатов.
 *
 * Этот файл содержит декларации функций, связанных с выводом
 * результатов решения задачи.
 */

/**
 * @brief Вывод корней квадратного уравнения.
 *
 * Функция принимает структуру Roots и выводит ее содержимое на экран.
 *
 * @param data Структура Roots, содержащая корни уравнения.
 */
void PrintRoots(struct Roots data);

#endif // PRINTER_H

