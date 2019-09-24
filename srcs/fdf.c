/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:36:08 by tigre             #+#    #+#             */
/*   Updated: 2019/02/22 19:39:09 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		free_tabs(t_mlx *mlx)
{
	int			i;

	i = 0;
	while (i < mlx->h)
		free(mlx->map[i++]);
	free(mlx->map);
}

int			fdf_exit(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		free_tabs(mlx);
		exit(0);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (error_handler(ARG));
	gen_map(&mlx, av[1]);
	ft_map_maker(&mlx);
	return (0);
}
