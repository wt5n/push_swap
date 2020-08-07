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

void ft_error()
{
	write(1, "Error\n", 6);
	exit(1);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;
	int	len_src;

	i = 0;
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	while (len_src && len)
	{
		dst[i] = src[i];
		len_src--;
		i++;
		len--;
	}
	while (len)
	{
		dst[i] = '\0';
		len--;
		i++;
	}
	return (dst);
}

void	ft_bzero(void *buf, size_t count)
{
	unsigned char *pointer;

	pointer = (unsigned char *)buf;
	while (count-- > 0)
		*(pointer++) = 0;
}

void	*ft_memalloc(size_t size)
{
	void *m;

	if (!(m = malloc(size)))
		return (NULL);
	ft_bzero(m, size);
	return (m);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *r;

	if (!s || !(r = ft_memalloc(len + 1)))
		return (NULL);
	r = ft_strncpy(r, (char *)s + start, len);
	return (r);
}

void ft_swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

static int partition(int *A, int p, int q)
{
	int i = p - 1;
	int j = p;
	while (j <= q)
	{
		if(A[j] <= A[q])
			ft_swap(&A[++i], &A[j]);
		j++;
	}
	return i;
}

void ft_quicksort(int *A, int p, int q)
{
	if(p < q)
	{
		int pivot = partition(A, p, q);
		ft_quicksort(A, p, pivot - 1);
		ft_quicksort(A, pivot + 1, q);
	}
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

int		ft_wordmalloc(char const *s, char **mass)
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

void	ft_rewriting(char const *s, char **mass)
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

char	**ft_strsplit_str(char const *s, int word)
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

void number_validation(const char *av)
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

int spaces_check(const char *av)
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

void check_dupl(t_stack *numbs)
{
	int *buff;
	int i;

	i = 0;
	if (!(buff = (int *)malloc(sizeof(int) * (numbs->n))))
		exit(1);
	buff = ft_intcpy(buff, numbs->a, numbs->n);
	numbs->stack_a = buff;
	ft_quicksort(buff, 0, numbs->n-1);
	while (i != numbs->n)
	{
		if(buff[i] == buff[i + 1])
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
		int a = -1;
		while (n_word > ++a)
			numbs->a[numbs->n + a] = buff[a];
		numbs->n += n_word;
		free(buff);
		i++;
	}
}

int validation(int ac, char **av, t_stack *numbs)
{
	int i;
	int ok;

	i = 1;
	ok = 0;
	while (i <= ac)
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