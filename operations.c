/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:14:29 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/10 13:14:29 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sa(t_stack *a, int print_comm)
{
	int c;
	c = a->value;
	a->value = a->next->value;
	a->next->value = c;
	if (print_comm)
		write(1, "sa\n", 3);
}

void ft_sb(t_stack *a, int print_comm)
{
	int c;

	if (a == NULL || a->next == NULL)
		return;
	c = a->value;
	a->value = a->next->value;
	a->next->value = c;
	if (print_comm)
		write(1, "sb\n", 3);
}

void ft_ss(t_stacks *res, int print_comm)
{
	ft_sa(res->a, 0);
	ft_sb(res->b, 0);
	if (print_comm)
		write(1, "ss\n", 3);
}

void ft_pa(t_stacks *res, int print_comm)
{
	t_stack *t;

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

void ft_pb(t_stacks *res, int print_comm)
{
	t_stack *t;

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

void ft_ra(t_stack **a, int print_comm)
{
	t_stack *k;
	t_stack *j;
	t_stack *i;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	j = *a;
	k = (*a)->next;
	i = *a;
	while (i->next != NULL)
		i = i->next;
	j->next = NULL;
	i->next = j;
	*a = k;
	if (print_comm)
		write(1, "ra\n", 3);
}

void ft_rb(t_stack **a, int print_comm)
{
	t_stack *k;
	t_stack *j;
	t_stack *i;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	j = *a;
	k = (*a)->next;
	i = *a;
	while (i->next != NULL)
		i = i->next;
	j->next = NULL;
	i->next = j;
	*a = k;
	if (print_comm)
		write(1, "rb\n", 3);
}

void ft_rr(t_stacks *res, int print_comm)
{
	if (print_comm)
		write(1, "rr\n", 3);
	ft_ra(&res->a, 0);
	ft_rb(&res->b, 0);
}

void ft_rra(t_stack **a, int print_comm)
{
	t_stack		*k;
	t_stack		*j;
	t_stack		*i;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	k = *a;
	i = *a;
	while (i->next->next != NULL)
		i = i->next;
	j = i->next;
	i->next = NULL;
	j->next = k;
	*a = j;
	if (print_comm)
		write(1, "rra\n", 4);
}

void ft_rrb(t_stack **a, int print_comm)
{
	t_stack		*k;
	t_stack		*j;
	t_stack		*i;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	k = *a;
	i = *a;
	while (i->next->next != NULL)
		i = i->next;
	j = i->next;
	i->next = NULL;
	j->next = k;
	*a = j;
	if (print_comm)
		write(1, "rrb\n", 4);
}

void ft_rrr(t_stacks *res, int print_comm)
{
	ft_rra(&res->a, 0);
	ft_rrb(&res->b, 0);
	if (print_comm)
		write(1, "rrr\n", 4);
}








