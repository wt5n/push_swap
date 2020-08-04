#include "push_swap.h"

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

int	ft_words(char const *s, char c)
{
	int		i;
	int		words;
	int		a;

	i = 0;
	words = 0;
	a = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && a == 1)
			a = 0;
		if (s[i] != c && a == 0)
		{
			a = 1;
			words++;
		}
		i++;
	}
	return (words);
}

static int		ft_wordmalloc(char const *s, char **mass)
{
	int lenword;
	int i;

	i = 0;
	while (*s)
	{
		lenword = 0;
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
			{
				s++;
				lenword++;
			}
			if (!(mass[i++] = ((char *)malloc(sizeof(char) * (lenword + 1)))))
				return (i);
		}
		else
			s++;
	}
	return (0);
}

static void	ft_rewriting(char const *s, char **mass)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				mass[i][j++] = *s++;
			mass[i++][j] = '\0';
		}
		j = 0;
		if (*s != '\0')
			s++;
	}
}

static char	**ft_strsplit_str(char const *s, int word)
{
	char	**mass;
	int		res;

	if (!s)
		return (NULL);
	if (!(mass = (char **)malloc(sizeof(char *) * (word + 1))))
		exit(1);
	mass[word] = NULL;
	res = ft_wordmalloc(s, mass);
	if (res == 0)
		ft_rewriting(s, mass);
	else
	{
		while (res != 0)
		{
			free(mass[res]);
			mass[res--] = NULL;
		}
		free(mass);
	}
	return ((char **)mass);
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
			{
				printf("Error\n");
				exit(1);
			}
			num = 0;
			sign = 0;
		}
		else if((av[i] == '+' || av[i] == '-') && (sign == 0 && num == 0) && (av[i + 1] != '\0'))
			sign++;
		else
		{
			printf("Error\n");
			exit(1);
		}
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

int main()
{
	t_stack *numbs;
	int ac = 5;
	char **av;
	av[1] = "1 2";
	av[2] = "4";
	av[3] = "5";
	av[4] = "3";
	av[5] = "7";
	if(ac < 2)
		exit(1);
	if (!(numbs = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	numbs->n = 0;
	if(validation(ac, av))
	{
		transformation(ac, av, numbs);
		printf("ok\n");
	}
	return 0;
}
