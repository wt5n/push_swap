/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:14:29 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/10 17:36:00 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

void		ft_sa(t_stack *a, int print_comm)
{
	int		c;

	if (a == NULL || a->next == NULL)
		return ;
	c = a->value;
	a->value = a->next->value;
	a->next->value = c;
	if (print_comm)
		write(1, "sa\n", 3);
}

void		ft_sb(t_stack *a, int print_comm)
{
	int		c;

	if (a == NULL || a->next == NULL)
		return ;
	c = a->value;
	a->value = a->next->value;
	a->next->value = c;
	if (print_comm)
		write(1, "sb\n", 3);
}

void		ft_ss(t_stacks *res, int print_comm)
{
	ft_sa(res->a, 0);
	ft_sb(res->b, 0);
	if (print_comm)
		write(1, "ss\n", 3);
}

void		ft_pa(t_stacks *res, int print_comm)
{
	t_stack	*t;

	if (res->b == NULL)
		return ;
	res->len_a++;
	res->len_b--;
	t = res->b;
	res->b = res->b->next;
	t->next = res->a;
	res->a = t;
	if (print_comm)
		write(1, "pa\n", 3);
}

void		ft_pb(t_stacks *res, int print_comm)
{
	t_stack	*t;

	if (res->a == NULL)
		return ;
	res->len_b++;
	res->len_a--;
	t = res->a;
	res->a = res->a->next;
	t->next = res->b;
	res->b = t;
	if (print_comm)
		write(1, "pb\n", 3);
}
