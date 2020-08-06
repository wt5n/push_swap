/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:15:08 by hlikely           #+#    #+#             */
/*   Updated: 2019/09/24 19:22:18 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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

static int	ft_len(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
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

char		**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		nword;
	int		i;

	i = 0;
	if (!s || !c)
		return (NULL);
	nword = ft_words(s, c);
	if (!(t = (char **)malloc(sizeof(*t) * (nword + 1))))
		return (NULL);
	while (nword--)
	{
		while (*s == c && *s != '\0')
			s++;
		t[i] = ft_strsub((const char *)s, 0, ft_len((const char *)s, c));
		if (t[i] == NULL)
			ft_free(t, i);
		s = s + ft_len(s, c);
		i++;
	}
	t[i] = NULL;
	return (t);
}
