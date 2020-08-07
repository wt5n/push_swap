#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"

typedef struct	s_stack
{
    int a[5000];
    int n;
	int *b;
	int steps;
	int unsorted;
	int max;
	int min;
}               t_stack;

int 			spaces_check(const char *av);
void 			number_validation(const char *av);
int 			validation(int ac, char **av, t_stack *numbs);
void 			check_dupl(t_stack *numbs);
void 			transformation(int ac, char **av, t_stack *numbs);
int				*ft_intcpy(int *str1, int *str2, int n);
void			ft_sa(t_stack *numbs);
void			ft_sb(t_stack *numbs);
void			ft_ss(t_stack *numbs);

#endif
