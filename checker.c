/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:13:43 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/10 17:19:48 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

void			actions(char *line, t_stacks *res)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(res->a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(res->b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(res, 0);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(res, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(res, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(&res->a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(&res->b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(res, 0);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(&res->a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(&res->b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(res, 0);
	else
		ft_error();
}

void			read_line(t_stacks *res)
{
	char		*str;

	str = NULL;
	while (get_next_line(0, &str))
	{
		actions(str, res);
		free(str);
		str = NULL;
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
}

int				stack_sort(t_stacks *res)
{
	int			i;
	t_stack		*s;
	int			buff;

	i = 0;
	s = res->a;
	while (i < (res->len_a - 1))
	{
		buff = res->a->value;
		res->a = res->a->next;
		if (buff > res->a->value)
		{
			res->a = s;
			return (0);
		}
		i++;
	}
	res->a = s;
	return (1);
}

int				main(int ac, char **av)
{
	t_info		*numbs;
	t_stacks	*res;

	if (ac < 2)
		exit(1);
	if (!(numbs = (t_info *)malloc(sizeof(t_info))))
		exit(1);
	if (!(res = (t_stacks *)malloc(sizeof(t_stacks))))
		exit(1);
	if (validation(ac, av, numbs))
	{
		res->print_comm = 0;
		initialize(numbs, res);
		read_line(res);
		if (stack_sort(res) && res->len_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_stack(res);
	free(numbs);
	free(res);
	return (0);
}
