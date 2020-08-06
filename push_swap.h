#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

typedef struct	s_stack
{
    int a[5000];
    int n;
}               t_stack;

typedef struct	s_stacks
{
	int *a;
	int *b;
	int steps;
}				t_stacks;



int spaces_check(char *av);
void number_validation(char *av);
int validation(int ac, char **av, t_stack numbs);
void check_dupl(t_stack numbs);
int	ft_words(char const *s);
void transformation(int ac, char **av, t_stack *numbs);
void ft_error();

#endif //UNTITLED_PUSH_SWAP_H
