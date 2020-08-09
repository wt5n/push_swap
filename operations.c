#include "./libft/libft.h"
#include "push_swap.h"

void ft_sa(t_info *res)
{
	ft_swap(&res->a[0], &res->a[1]);
	write(1, "sa\n", 3);
}

void ft_sb(t_info *res)
{
	ft_swap(&res->b[0], &res->b[1]);
	write(1, "sb\n", 3);
}

void ft_ss(t_info *res)
{
	ft_sa(res);
	ft_sb(res);
	write(1, "ss\n", 3);
}

void ft_pa(t_info *res)
{

}








