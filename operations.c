#include "./libft/libft.h"
#include "push_swap.h"

void ft_sa(t_stack *numbs)
{
	ft_swap(&numbs->a[0], &numbs->a[1]);
	write(1, "sa\n", 3);
}

void ft_sb(t_stack *numbs)
{
	ft_swap(&numbs->b[0], &numbs->b[1]);
	write(1, "sb\n", 3);
}

void ft_ss(t_stack *numbs)
{
	ft_sa(numbs);
	ft_sb(numbs);
	write(1, "ss\n", 3);
}










