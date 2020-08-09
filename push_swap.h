#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"

typedef struct	s_info
{
    int a[5000];
    int n;
	int unsorted;
}               t_info;

typedef struct s_stack
{
	int value;
	int step;
	struct s_stack *next;
}				t_stack;

typedef struct s_stacks
{
	t_stack *a;
	t_stack *b;
	int len_a;
	int len_b;
	int max;
	int min;
}				t_stacks;

int 			spaces_check(int ac, const char *av);
void 			number_validation(const char *av);
int 			validation(int ac, char **av, t_info *numbs);
void 			check_dupl(t_info *numbs);
void 			transformation(int ac, char **av, t_info *numbs);
int				*ft_intcpy(int *str1, int *str2, int n);
void			ft_sa(t_stacks *res);
void			ft_sb(t_stacks *res);
void			ft_ss(t_stacks *res);
void 			ft_ra(t_stacks *res);
void 			ft_rb(t_stacks *res);
void 			ft_rr(t_stacks *res);
void 			ft_rra(t_stacks *res);
void 			ft_rrb(t_stacks *res);
void 			ft_rrr(t_stacks *res);
void 			ft_pa(t_stacks *res);
void 			ft_pb(t_stacks *res);


#endif
