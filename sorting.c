/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:41:08 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/10 17:41:15 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

void	ft_sorting(t_stacks *res)
{
	while (res->len_a > 2)
	{
		if (res->a->value != res->min && res->a->value != res->max)
		{
			ft_pb(res, 1);
			if (res->b->value > res->med)
				ft_rb(&res->b, 1);
		}
		else
			ft_ra(&res->a, 1);
	}
	if (res->a->value < res->a->next->value)
		ft_sa(res->a, 1);
	ft_pa(res, 1);
	ft_start_sort(res);
}

void	ft_start_sort(t_stacks *res)
{
	t_stacks *step;

	if (!(step = (t_stacks *)malloc(sizeof(t_stacks))))
		exit(1);
	while (res->len_b != 0)
	{
		step->slen_a = -1;
		step->slen_b = -1;
		step->dest_a = 0;
		step->dest_b = 0;
		ft_steps_markup(res->a, res->len_a);
		ft_steps_markup(res->b, res->len_b);
		ft_minimum_insertion_steps(res, step);
		ft_instruction_execution(res, step);
	}
	if ((ft_count_to_min(res->a, res->min)) > res->len_a / 2)
	{
		while (res->a->value != res->min)
			ft_rra(&res->a, 1);
	}
	else
		while (res->a->value != res->min)
			ft_ra(&res->a, 1);
	free(step);
}

void	ft_steps_markup(t_stack *b, int count)
{
	int		i;
	int		iter;
	t_stack	*buff;

	i = -1;
	iter = count / 2;
	buff = b;
	while (++i <= iter)
	{
		buff->step = i;
		buff->rotate = 1;
		buff = buff->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->rotate = -1;
		buff = buff->next;
	}
}

void	ft_minimum_insertion_steps(t_stacks *res, t_stacks *steps)
{
	int		min_action;
	t_stack	*first_a;
	t_stack	*first_b;

	min_action = -1;
	first_a = res->a;
	first_b = res->b;
	while (res->b)
	{
		min_action = ft_finding_place(res, res->b, steps, min_action);
		res->a = first_a;
		res->b = res->b->next;
	}
	res->b = first_b;
}

void	ft_instruction_execution(t_stacks *res, t_stacks *steps)
{
	while (steps->slen_a > 0)
	{
		if (steps->dest_a == 1)
			ft_ra(&res->a, 1);
		else
			ft_rra(&res->a, 1);
		steps->slen_a--;
	}
	while (steps->slen_b > 0)
	{
		if (steps->dest_b == 1)
			ft_rb(&res->b, 1);
		else
			ft_rrb(&res->b, 1);
		steps->slen_b--;
	}
	ft_pa(res, 1);
}
