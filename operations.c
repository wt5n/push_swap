#include "./libft/libft.h"

static unsigned long long	max_min(char *s, int sign)
{
	unsigned long long		re;
	int						i;

	i = 0;
	re = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		re = (re * 10) + (s[i] - '0');
		i++;
	}
	if (sign == -1)
	{
		if (re >= 9223372036854775807)
			return (0);
	}
	if (re >= 9223372036854775807)
		return (-1);
	return (re);
}

int							ft_atoi(const char *str)
{
	char					*s;
	unsigned long long		r;
	int						sign;
	int						i;

	r = 0;
	s = (char *)str;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' ||\
	s[i] == '\f' || s[i] == '\r' || s[i] == '\v')
		i++;
	sign = (s[i] == '-') ? -1 : 1;
	s = (s[i] == '+' || s[i] == '-') ? s + 1 : s;
	r = max_min(s + i, sign);
	return ((int)r * sign);
}

int	ft_words(char const *s)
{
	int		i;
	int		words;
	int		a;

	i = -1;
	words = 0;
	a = 0;
	while (s[++i] != '\0')
	{
		if ((s[i] != ' ' && s[i] != '\t') && a == 0)
		{
			a = 1;
			words++;
		}
		if ((s[i] == ' ' || s[i] == '\t') && a == 1)
			a = 0;
	}
	return (words);
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

void ft_error()
{
	ft_putstr("Error\n");
	exit(1);
}

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

int validation(int ac, char **av)
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
	return (ok);
}
