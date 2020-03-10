/*
** EPITECH PROJECT, 2019
** calcul.c
** File description:
** calcul
*/

#include <stdlib.h>
#include "my.h"

void add_matrix_1_3(ope_t *ope, double **stock)
{
    stock[0][0] = ope->start[0];
    stock[0][1] = ope->start[1];
    stock[0][2] = ope->start[2];
    ope->start[0] = stock[0][0] * ope->matrix[0][0][0]
        + stock[0][1] * ope->matrix[0][0][1]
        + stock[0][2] * ope->matrix[0][0][2];
    ope->start[1] = stock[0][0] * ope->matrix[0][1][0]
        + stock[0][1] * ope->matrix[0][1][1]
        + stock[0][2] * ope->matrix[0][1][2];
    ope->start[2] = stock[0][0] * ope->matrix[0][2][0]
        + stock[0][1] * ope->matrix[0][2][1]
        + stock[0][2] * ope->matrix[0][2][2];
}

double mult_matrix_3_3(ope_t *ope, int i, int y, int x)
{
    return (
        ope->matrix[i][y][0] * ope->matrix[0][0][x]
        + ope->matrix[i][y][1] * ope->matrix[0][1][x]
        + ope->matrix[i][y][2] * ope->matrix[0][2][x]);
}

void matrixcpy(double **stock, double **matrix)
{
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 3; i++)
            matrix[j][i] = stock[j][i];
}

void add_matrix_3_3(double **stock, ope_t *ope, int i)
{
    stock[0][0] = mult_matrix_3_3(ope, i, 0, 0);
    stock[0][1] = mult_matrix_3_3(ope, i, 0, 1);
    stock[0][2] = mult_matrix_3_3(ope, i, 0, 2);
    stock[1][0] = mult_matrix_3_3(ope, i, 1, 0);
    stock[1][1] = mult_matrix_3_3(ope, i, 1, 1);
    stock[1][2] = mult_matrix_3_3(ope, i, 1, 2);
    stock[2][0] = mult_matrix_3_3(ope, i, 2, 0);
    stock[2][1] = mult_matrix_3_3(ope, i, 2, 1);
    stock[2][2] = mult_matrix_3_3(ope, i, 2, 2);
    matrixcpy(stock, ope->matrix[0]);
}

bool calc(int size, ope_t *ope)
{
    double **stock = malloc(sizeof(double *) * 3);

    if (stock == NULL)
        return (false);
    for (int i = 0; i < 3; i++) {
        stock[i] = malloc(sizeof(double) * 3);
        if (stock[i] == NULL)
            return (false);
    }
    for (int i = 1; i < size; i++)
        add_matrix_3_3(stock, ope, i);
    print_matrix(ope, stock);
    free_all(ope, stock, size);
    return (true);
}
