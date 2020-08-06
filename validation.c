#include "push_swap.h"

void number_validation(char *av)
{
	int i;
	int num;
	int sign;

	i = 0;
	num = 0;
	sign = 0;
	while (av[i] != '\0')
	{
		if(av[i] >= '0' && av[i] <= '9')
			num++;
		else if(av[i] == ' ' || av[i] == '\t')
		{
			if(num == 0 && sign != 0)
				ft_error();
			num = 0;
			sign = 0;
		}
		else if((av[i] == '+' || av[i] == '-') && (sign == 0 && num == 0) &&
				(av[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

int spaces_check(char *av)
{
	int i;

	i = 0;
	while(av[i] != '\0')
	{
		if (av[i] == ' ' || av[i] == '\n' || av[i] == '\r' || av[i] == '\t' || av[i] == '\v' || av[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}

void check_dupl(t_stack numbs)
{
	int *buff;
	int i;

	i = 0;
	if (!(buff = (int *)malloc(sizeof(int) * (numbs->n))))
		exit(1);
	buff = ft_stackcpy(buff, numbs);
	ft_quicksort(buff, 0, numbs->n-1);
	while (i != numbs->n)
		if (buff[i] == buff[i++])
			ft_error();
}

void transformation(const int ac, char **av, t_stack *numbs)
{
	int *buff;
	char **buffer;
	int i;
	int n_word;
	int j;

	i = 1;
	while (i <= ac)
	{
		j = -1;
		n_word = ft_words(av[i], ' ');
		buffer = ft_strsplit_str(av[i], n_word);
		if (!(buff = (int *)malloc(sizeof(int) * (n_word))))
			exit(1);
		while (n_word > ++j)
		{
			buff[j] = ft_atoi(buffer[j]);
			free(buffer[j]);
		}
		free(buffer);
		int a = -1;
		while (n_word > ++a)
		{
			numbs->a[numbs->n + a] = buff[a];
			printf("%d\n", numbs->a[a]);
		}
		numbs->n += n_word;
		free(buff);
		i++;
	}
}

int validation(int ac, char **av, t_stack numbs)
{
	int i;
	int ok;

	i = 1;
	ok = 0;
	while (i < ac)
	{
		if (spaces_check(av[i]))
		{
			number_validation(av[i]);
			ok = 1;
		}
		i++;
	}
	if (ok)
	{
		transformation(ac, av, numbs);
		check_dupl(numbs);
	}
	return (ok);
}