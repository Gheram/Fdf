/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:02:43 by tigre             #+#    #+#             */
/*   Updated: 2019/02/22 19:39:42 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	len_line(char *line)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			len++;
			while (line[i] && line[i] == ' ')
				i++;
			if (line[i] == '\0')
				return (len);
		}
		i++;
	}
	return (len + 1);
}

static void	get_size_map(t_mlx *mlx, char *line, char *name)
{
	int		fd;

	if ((fd = open(name, O_RDONLY)) == -1)
		error_handler(FD);
	mlx->h = 0;
	while (get_next_line(fd, &line))
	{
		(mlx->h)++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
}

static int	malloc_tab(t_mlx *mlx, char *line, int y)
{
	int		i;
	int		x;
	int		tmp;

	i = 0;
	x = 0;
	tmp = len_line(line);
	if (mlx->w > tmp)
		error_handler(MAP);
	if (!(mlx->map[y] = (int*)malloc(sizeof(int) * tmp)))
		error_handler(MLC);
	while (line[i])
	{
		while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
			i++;
		if (line[i] && x < tmp)
			mlx->map[y][x++] = ft_atoi(line + i);
		while (line[i] && line[i] != ' ')
			i++;
	}
	ft_strdel(&line);
	return (0);
}

void		gen_map(t_mlx *mlx, char *name)
{
	char	*line;
	int		y;
	int		fd;

	line = NULL;
	y = 0;
	get_size_map(mlx, line, name);
	if ((fd = open(name, O_RDONLY)) == -1)
		error_handler(FD);
	if (!(mlx->map = (int **)malloc(sizeof(int*) * mlx->h)))
		error_handler(MLC);
	get_next_line(fd, &line);
	mlx->w = len_line(line);
	malloc_tab(mlx, line, y++);
	while (get_next_line(fd, &line))
		malloc_tab(mlx, line, y++);
	close(fd);
}
