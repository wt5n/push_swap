/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:08:24 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/10 18:15:54 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define MAXINT 2147483647
# define MININT -2147483648
# define BUFF_SIZE	8
# define FD_SIZE	10240

int					ft_atoi(const char *str);
void				ft_bzero(void *buf, size_t count);
void				ft_error(void);
int					*ft_intcpy(int *str1, int *str2, int n);
void				*ft_memalloc(size_t size);
void				ft_quicksort(int *str, int p, int q);
char				*ft_strchr(const char *str, int ch);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
char				*ft_strnew(size_t size);
char				**ft_strsplit_str(char const *s, int word);
void				ft_swap(int *a, int *b);
int					get_next_line(const int fd, char **line);
int					ft_words(char const *s);

#endif
