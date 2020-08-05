#include "push_swap.h"

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
