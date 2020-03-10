/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdbool.h>

typedef struct ope_t
{
    double *start;
    double ***matrix;
    char *flag;
} ope_t;

int print_descr(char *file);
int archi(int ac, char **av);
int check_syntax(int ac, char **av, int i);
int check_int(char *nb);
bool calc(int size, ope_t *ope);
void init_ope(int ac, char **av, ope_t *ope);
int count_flags(int ac, char **av);
void add_matrix_1_3(ope_t *ope, double **stock);
void print_action(ope_t *ope, int i, char *x, char *y);
void print_matrix(ope_t *ope, double **stock);
void free_all(ope_t *ope, double **stock, int size);

#endif
