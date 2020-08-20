/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:14:45 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/19 16:54:27 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

int		ft_max(t_stack *s)
{
	int max;

	max = s->value;
	while (s)
	{
		if (s->value > max)
			max = s->value;
		s = s->next;
	}
	return (max);
}

void	sort_3(t_stacks *res)
{
	int	max;

	max = 0;
	max = ft_max(res->a);
	if (res->len_a == 2)
		if (res->a->value > res->a->next->value)
			ft_sa(res->a, res->print_comm);
	if (res->len_a == 3)
	{
		if (res->a->value == max)
			ft_ra(&res->a, res->print_comm);
		if (res->a->next->value == max)
			ft_rra(&res->a, res->print_comm);
		if (res->a->value > res->a->next->value)
			ft_sa(res->a, res->print_comm);
	}
}

void	sort_5(t_stacks *res)
{
	while (res->len_b < 2)
	{
		if (res->a->value == res->min || res->a->value == res->max)
			ft_pb(res, res->print_comm);
		else
			ft_ra(&res->a, res->print_comm);
	}
	sort_3(res);
	ft_pa(res, res->print_comm);
	ft_pa(res, res->print_comm);
	if (res->a->value == res->max)
		ft_ra(&res->a, res->print_comm);
	else
	{
		ft_sa(res->a, res->print_comm);
		ft_ra(&res->a, res->print_comm);
	}
}

void	ft_sort(t_stacks *res)
{
	if (res->len_a == 1)
		return ;
	else if (res->len_a <= 3)
		sort_3(res);
	else if (res->len_a <= 5)
		sort_5(res);
	else
		ft_sorting(res);
}

int		main(int ac, char **av)
{
	t_info		*numbs;
	t_stacks	*res;

	if (ac < 2)
		exit(1);
	if (!(numbs = (t_info *)malloc(sizeof(t_info))))
		exit(1);
	if (!(res = (t_stacks *)malloc(sizeof(t_stacks))))
		exit(1);
	ft_null(numbs, res);
	if (validation(ac, av, numbs))
	{
		res->print_comm = 1;
		initialize(numbs, res);
		if (numbs->unsorted == 1)
			ft_sort(res);
	}
	free_stack(res);
	free(numbs);
	free(res);
	return (0);
}
