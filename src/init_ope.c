/*
** EPITECH PROJECT, 2019
** init_ope.c
** File description:
** init ope
*/

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "my.h"

int count_flags(int ac, char **av)
{
    int count = 0;

    for (int i = 3; i < ac; i++)
        if (strcmp(av[i], "-t") == 0 || strcmp(av[i], "-z") == 0
            || strcmp(av[i], "-r") == 0 || strcmp(av[i], "-s") == 0)
            count++;
    return (count);
}

void fill_mtx(ope_t *ope, int i, double x, double y)
{
    if (ope->flag[i] == 't') {
        ope->matrix[i][0][2] = x;
        ope->matrix[i][1][2] = y;
    }
    if (ope->flag[i] == 'z') {
        ope->matrix[i][0][0] = x;
        ope->matrix[i][1][1] = y;
    }
    if (ope->flag[i] == 'r') {
        ope->matrix[i][0][0] = cos(x / 180 * M_PI);
        ope->matrix[i][1][1] = cos(x / 180 * M_PI);
        ope->matrix[i][0][1] = -sin(x / 180 * M_PI);
        ope->matrix[i][1][0] = sin(x / 180 * M_PI);
    }
    if (ope->flag[i] == 's') {
        ope->matrix[i][0][0] = cos(2 * x / 180 * M_PI);
        ope->matrix[i][1][1] = -cos(2 * x / 180 * M_PI);
        ope->matrix[i][0][1] = sin(2 * x / 180 * M_PI);
        ope->matrix[i][1][0] = sin(2 * x / 180 * M_PI);
    }
}

void init_ope(int ac, char **av, ope_t *ope)
{
    int j = 0;

    ope->start[0] = atof(av[1]);
    ope->start[1] = atof(av[2]);
    ope->start[2] = 1;
    for (int i = 3; i < ac; i++) {
        if (strcmp(av[i], "-t") == 0 || strcmp(av[i], "-z") == 0) {
            ope->flag[j] = av[i][1];
            print_action(ope, j, av[i + 1], av[i + 2]);
            fill_mtx(ope, j, atof(av[i + 1]), atof(av[i + 2]));
            j++;
        } else if (strcmp(av[i], "-r") == 0 || strcmp(av[i], "-s") == 0) {
            ope->flag[j] = av[i][1];
            print_action(ope, j, av[i + 1], 0);
            fill_mtx(ope, j, atof(av[i + 1]), 0);
            j++;
        }
    }
    ope->flag[j] = '\0';
}
