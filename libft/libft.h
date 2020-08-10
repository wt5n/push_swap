/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:08:24 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/10 16:14:21 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE	8
# define FD_SIZE	10240

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *buf, size_t count);
void 	ft_error(void);
int		*ft_intcpy(int *str1, int *str2, int n);
void	*ft_memalloc(size_t size);
void 	ft_quicksort(int *A, int p, int q);
char	*ft_strchr(const char *str, int ch);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		get_next_line(const int fd, char **line);

#endif
