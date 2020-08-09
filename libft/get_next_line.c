/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 08:08:29 by hlikely           #+#    #+#             */
/*   Updated: 2019/11/22 17:58:30 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		read_line(char **st, char **line, const int fd)
{
	*line = ft_strdup(st[fd]);
	free(st[fd]);
	st[fd] = NULL;
	return (1);
}

static int		read_file(char **st, const int fd)
{
	char		buf[BUFF_SIZE + 1];
	int			r;
	char		*tmp;

	tmp = NULL;
	if ((r = read(fd, buf, BUFF_SIZE)) == 0)
		return (0);
	buf[r] = '\0';
	tmp = ft_strjoin(st[fd], buf);
	free(st[fd]);
	st[fd] = ft_strdup(tmp);
	free(tmp);
	return (1);
}

static void			last_4str(char **line, const int fd, char **st, char *tmp)
{
	*line = ft_strdup(st[fd]);
	free(st[fd]);
	st[fd] = ft_strdup(tmp);
	free(tmp);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*st[FD_SIZE];
	char		*tmp;
	char		*p;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (!st[fd])
		st[fd] = ft_strnew(0);
	while ((p = ft_strchr(st[fd], '\n')) == NULL)
		if ((read_file(st, fd)) == 0)
			break ;
	if (ft_strlen(st[fd]) != 0)
	{
		if (!(ft_strchr(st[fd], '\n')))
			return (read_line(st, &*line, fd));
		*p = '\0';
		tmp = ft_strdup(p + 1);
		last_4str(line, fd, st, tmp);
	}
	else
		return (0);
	return (1);
}
