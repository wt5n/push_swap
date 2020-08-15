/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:40:04 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/11 17:04:22 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

void	best_pos_c(t_stacks *s, t_stack *b, int *act, int *buff)
{
	while (s->a)
	{
		*buff = s->a->value;
		if (b->value > s->a->value)
		{
			*act += 1;
			if (b->value < s->a->next->value)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
	if (min_elem(s->a, *buff, b->value) == 1)
	{
		while (s->a)
		{
			if (s->a->value < *buff && s->a->value > b->value)
				break ;
			*act += 1;
			s->a = s->a->next;
		}
	}
}

int		best_pos(t_stacks *s, t_stack *b, t_stacks *steps, int min)
{
	int action;
	int res;
	int buff;

	action = 0;
	buff = 0;
	best_pos_c(s, b, &action, &buff);
	if (s->a->rotate == -1)
		action = s->len_a - action;
	if (min == -1 || (action + b->step) < min)
	{
		steps->dest_a = s->a->rotate;
		steps->dest_b = b->rotate;
		steps->slen_a = action;
		steps->slen_b = b->step;
		res = action + b->step;
	}
	else
		res = min;
	return (res);
}

int		min_elem(t_stack *a, int buff, int src)
{
	t_stack	*save;
	int		ret;

	save = a;
	ret = 0;
	while (save && ret == 0)
	{
		if (save->value < buff && save->value > src)
			ret = 1;
		save = save->next;
	}
	return (ret);
}

int		ft_count_to_min(t_stack *a, int min)
{
	int i;

	i = 0;
	while (a)
	{
		if (a->value == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}

void	ft_null(t_info *numbs, t_stacks *res)
{
	numbs->unsorted = 0;
	numbs->min = 0;
	numbs->max = 0;
	numbs->med = 0;
	numbs->n = 0;
	res->max = 0;
	res->min = 0;
	res->med = 0;
	res->a = 0;
	res->b = 0;
	res->len_a = 0;
	res->len_b = 0;
	res->slen_a = 0;
	res->slen_b = 0;
	res->dest_a = 0;
	res->dest_b = 0;
}
