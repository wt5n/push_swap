/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:34:50 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/10 17:38:48 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

void		ft_ra(t_stack **a, int print_comm)
{
	t_stack	*k;
	t_stack	*j;
	t_stack	*i;

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

void		ft_rb(t_stack **a, int print_comm)
{
	t_stack	*k;
	t_stack	*j;
	t_stack	*i;

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

void		ft_rr(t_stacks *res, int print_comm)
{
	if (print_comm)
		write(1, "rr\n", 3);
	ft_ra(&res->a, 0);
	ft_rb(&res->b, 0);
}

void		ft_rra(t_stack **a, int print_comm)
{
	t_stack	*k;
	t_stack	*j;
	t_stack	*i;

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

void		ft_rrb(t_stack **a, int print_comm)
{
	t_stack	*k;
	t_stack	*j;
	t_stack	*i;

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
