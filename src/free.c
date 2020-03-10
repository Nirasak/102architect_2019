/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** free
*/

#include <stdlib.h>
#include "my.h"

void free_all(ope_t *ope, double **stock, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++)
            free(ope->matrix[i][j]);
        free(ope->matrix[i]);
    }
    for (int j = 0; j < 3; j++)
        free(stock[j]);
    free(stock);
    free(ope->flag);
    free(ope->start);
    free(ope->matrix);
}
