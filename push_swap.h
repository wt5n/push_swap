#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_stack
{
    int a[5000];
    int n;
}               t_stack;



int spaces_check(char *av);
void number_validation(char *av);
int validation(int ac, char **av);
int	ft_words(char const *s, char c);
void transformation(int ac, char **av, t_stack *numbs);

#endif //UNTITLED_PUSH_SWAP_H
