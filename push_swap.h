#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

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

int spaces_check(const char *av);
void number_validation(const char *av);
int validation(int ac, char **av, t_stack *numbs);
void check_dupl(t_stack *numbs);
void transformation(int ac, char **av, t_stack *numbs);
int	*ft_intcpy(int *str1, const t_stack *str2);

#endif
