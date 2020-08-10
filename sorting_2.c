/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:40:04 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/10 17:40:04 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

void	ft_help_finding_place(t_stacks *s, t_stack *b, int *action, int *buff)
{
	while (s->a)
	{
		*buff = s->a->value;
		if (b->value > s->a->value)
		{
			*action += 1;
			if (b->value < s->a->next->value)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
	if (ft_smaller_element_detection(s->a, *buff, b->value) == 1)
	{
		while (s->a)
		{
			if (s->a->value < *buff && s->a->value > b->value)
				break ;
			*action += 1;
			s->a = s->a->next;
		}
	}
}

int		ft_finding_place(t_stacks *s, t_stack *b, t_stacks *steps, int min)
{
	int action;
	int res;
	int buff;

	action = 0;
	buff = 0;
	ft_help_finding_place(s, b, &action, &buff);
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

int		ft_smaller_element_detection(t_stack *a, int buff, int src)
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
