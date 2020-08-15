/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:38:40 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/15 21:08:08 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

void			number_validation(const char *av)
{
	int			i;
	int			num;
	int			sign;

	i = 0;
	num = 0;
	sign = 0;
	while (av[i] != '\0')
	{
		if (av[i] >= '0' && av[i] <= '9')
			num++;
		else if (av[i] == ' ' || av[i] == '\t')
		{
			if (num == 0 && sign != 0)
				ft_error();
			num = 0;
			sign = 0;
		}
		else if ((av[i] == '+' || av[i] == '-') && (sign == 0 && num == 0) &&
				(av[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

int				spaces_check(int ac, const char *av)
{
	int			i;

	i = 0;
	while (i < ac)
	{
		if (av[i] == ' ' || av[i] == '\n' || av[i] == '\r' ||
		av[i] == '\t' || av[i] == '\v' || av[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}

void			check_duplicate(t_info *numbs)
{
	int			*buff;
	int			i;

	i = 0;
	if (!(buff = (int *)ft_memalloc(sizeof(int) * (numbs->n + 10))))
		exit(1);
	buff = ft_intcpy(buff, numbs->a, numbs->n);
	ft_quicksort(buff, 0, numbs->n - 1);
	while (i != numbs->n)
	{
		if (buff[i] == buff[i + 1])
			ft_error();
		i++;
	}
	i = 0;
	while (i < (numbs->n - 1))
	{
		if (numbs->a[i] > numbs->a[i + 1])
			numbs->unsorted = 1;
		i++;
	}
	numbs->max = buff[numbs->n - 1];
	numbs->min = buff[0];
	numbs->med = buff[numbs->n / 2];
	free(buff);
}

void			transformation(const int ac, char **av, t_info *numbs)
{
	int			*buff;
	char		**buffer;
	int			i;
	int			n_word;
	int			j;

	i = 1;
	while (i < ac)
	{
		j = -1;
		n_word = ft_words(av[i]);
		buffer = ft_strsplit_str(av[i], n_word);
		if (!(buff = (int *)malloc(sizeof(int) * (n_word))))
			exit(1);
		while (n_word > ++j)
		{
			buff[j] = ft_atoi(buffer[j]);
			free(buffer[j]);
		}
		free(buffer);
		to_info(numbs, buff, n_word);
		i++;
	}
}

int				validation(int ac, char **av, t_info *numbs)
{
	int			i;
	int			ok;

	i = 1;
	ok = 0;
	while (i < ac)
	{
		if (spaces_check(ac, av[i]))
		{
			number_validation(av[i]);
			ok = 1;
		}
		i++;
	}
	if (ok)
	{
		transformation(ac, av, numbs);
		check_duplicate(numbs);
	}
	return (ok);
}
