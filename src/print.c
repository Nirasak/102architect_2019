/*
** EPITECH PROJECT, 2019
** print_action.c
** File description:
** print action
*/

#include "my.h"
#include <stdio.h>

#define POS(x) ((x >= 0) ? x : (x > -0.01 ? (-x) : x))

void print_action(ope_t *ope, int i, char *x, char *y)
{
    if (ope->flag[i] == 't')
        printf("Translation along vector (%s, %s)\n", x, y);
    if (ope->flag[i] == 'z')
        printf("Scaling by factors %s and %s\n", x, y);
    if (ope->flag[i] == 'r')
        printf("Rotation by a %s degree angle\n", x);
    if (ope->flag[i] == 's')
        printf(
            "Reflection over an axis with an inclination angle"
            " of %s degrees\n", x);
}

void print_matrix(ope_t *ope, double **stock)
{
    printf(
        "%-8.2f%-8.2f%.2f\n", POS(ope->matrix[0][0][0]),
        POS(ope->matrix[0][0][1]), POS(ope->matrix[0][0][2]));
    printf(
        "%-8.2f%-8.2f%.2f\n", POS(ope->matrix[0][1][0]),
        POS(ope->matrix[0][1][1]), POS(ope->matrix[0][1][2]));
    printf(
        "%-8.2f%-8.2f%.2f\n", POS(ope->matrix[0][2][0]),
        POS(ope->matrix[0][2][1]), POS(ope->matrix[0][2][2]));
    printf("(%.2f, %.2f) => (", POS(ope->start[0]), POS(ope->start[1]));
    add_matrix_1_3(ope, stock);
    printf("%.2f, %.2f)\n", POS(ope->start[0]), POS(ope->start[1]));
}
