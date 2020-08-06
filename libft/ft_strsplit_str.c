#include "../inc/libft.h"

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

static int	ft_len(const char *s)
{
	int		len;

	len = 0;
	while (*s != ' ' || *s != '\t' && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_free(char **t, int i)
{
	if (i > 0)
	{
		i--;
		while (i != -1)
		{
			free(t[i]);
			i--;
		}
	}
	free(t);
	return (NULL);
}

char		**ft_strsplit_str(char const *s)
{
	char	**t;
	int		nword;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nword = ft_words(s);
	if (!(t = (char **)malloc(sizeof(*t) * (nword + 1))))
		exit(1);
	while (nword--)
	{
		while ((*s == ' ' || *s == '\t') && *s != '\0')
			s++;
		t[i] = ft_strsub((const char *)s, 0, ft_len((const char *)s));
		if (t[i] == NULL)
			ft_free(t, i);
		s = s + ft_len(s);
		i++;
	}
	t[i] = NULL;
	return (t);
}
