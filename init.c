/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:11:19 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/10 18:31:14 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

t_stack		*init_stack(const int *stack, int n)
{
	t_stack *a;
	t_stack *b;
	int		i;

	i = 0;
	if (!(a = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	b = a;
	while (i < n)
	{
		if (i < n - 1)
			if (!(a->next = (t_stack *)malloc(sizeof(t_stack))))
				exit(1);
		a->value = stack[i];
		if (i == (n - 1))
			a->next = NULL;
		else
			a = a->next;
		i++;
	}
	return (b);
}

void		initialize(t_info *numbs, t_stacks *res)
{
	res->b = NULL;
	res->a = init_stack(numbs->a, numbs->n);
	res->len_a = numbs->n;
	res->len_b = 0;
	res->max = numbs->max;
	res->med = numbs->med;
	res->min = numbs->min;
}

void		to_info(t_info *numbs, int *buff, int n_word)
{
	int		i;

	i = -1;
	while (n_word > ++i)
		numbs->a[numbs->n + i] = buff[i];
	numbs->n += n_word;
	free(buff);
}

void		ft_rrr(t_stacks *res, int print_comm)
{
	ft_rra(&res->a, 0);
	ft_rrb(&res->b, 0);
	if (print_comm)
		write(1, "rrr\n", 4);
}

void	ft_free_stack(t_stacks *stacks)
{
	int		i;
	t_stack	*buff;

	i = 0;
	while (i < stacks->len_a)
	{
		buff = stacks->a;
		stacks->a = stacks->a->next;
		free(buff);
		i++;
	}
	i = 0;
	while (i < stacks->len_b)
	{
		buff = stacks->b;
		stacks->b = stacks->b->next;
		free(buff);
		i++;
	}
}