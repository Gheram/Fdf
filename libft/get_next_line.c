/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:34:27 by ghtouman          #+#    #+#             */
/*   Updated: 2019/01/14 16:55:49 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		clean_fds(char **line, char **fds, char *tmp, int fd)
{
	char *bn;

	bn = ft_strchr(fds[fd], '\n');
	if (bn == NULL)
	{
		*line = fds[fd];
		fds[fd] = NULL;
		return (1);
	}
	*bn = '\0';
	*line = ft_strdup(fds[fd]);
	tmp = ft_strdup(bn + 1);
	if (*line == NULL || tmp == NULL)
		return (-1);
	free(fds[fd]);
	fds[fd] = tmp;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;
	static char	**fds = NULL;

	if (fds == NULL)
		if (!(fds = ft_memalloc(sizeof(char*) * 5000)))
			return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(fds[fd], buff);
		if (tmp == NULL)
			return (-1);
		free(fds[fd]);
		fds[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && ft_strlen(fds[fd]) == 0)
		return (0);
	return (clean_fds(line, fds, tmp, fd));
}
