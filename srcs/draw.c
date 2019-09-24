/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:43:14 by tigre             #+#    #+#             */
/*   Updated: 2019/02/22 19:40:55 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		draw_line(t_mlx *mlx, int x, int y)
{
	double		dx;
	double		dy;
	double		temp;
	double		x1;
	double		y1;

	x1 = mlx->x1;
	y1 = mlx->y1;
	dx = mlx->x2 - x1;
	dy = mlx->y2 - y1;
	temp = sqrt((dx * dx) + (dy * dy));
	dx /= temp;
	dy /= temp;
	while (temp >= 0)
	{
		put_px_image(x1, y1, mlx, color(mlx, x, y));
		x1 += dx;
		y1 += dy;
		temp--;
	}
	return (0);
}

static void		found_coordinates(t_mlx *mlx, int x, int y, int bas)
{
	int			xt;
	int			yt;

	xt = x - mlx->w / 2;
	yt = y - mlx->h / 2;
	mlx->x1 = (xt - yt) * mlx->zoom;
	mlx->y1 = mlx->projection * (xt + yt) * mlx->zoom;
	mlx->y1 -= mlx->map[y][x] * mlx->z;
	if (bas)
	{
		mlx->x2 = ((xt + 1) - yt) * mlx->zoom;
		mlx->y2 = mlx->projection * ((xt + 1) + yt) * mlx->zoom;
		mlx->y2 -= mlx->map[y][x + 1] * mlx->z;
	}
	else
	{
		mlx->x2 = (xt - (yt + 1)) * mlx->zoom;
		mlx->y2 = mlx->projection * (xt + (yt + 1)) * mlx->zoom;
		mlx->y2 -= mlx->map[y + 1][x] * mlx->z;
	}
	mlx->x1 += HEIGHT / 2.5 + 450;
	mlx->x2 += HEIGHT / 2.5 + 450;
	mlx->y1 += WIDTH / 2.5 - 300;
	mlx->y2 += WIDTH / 2.5 - 300;
}

static void		draw_map(t_mlx *mlx)
{
	int			x;
	int			y;

	y = 0;
	while (y < mlx->h)
	{
		x = 0;
		while (x < mlx->w)
		{
			if (x + 1 < mlx->w)
			{
				found_coordinates(mlx, x, y, 1);
				draw_line(mlx, x, y);
			}
			if (y + 1 < mlx->h)
			{
				found_coordinates(mlx, x, y, 0);
				draw_line(mlx, x, y);
			}
			x++;
		}
		y++;
	}
}

static int		img_handler(t_mlx *mlx)
{
	int			b_p_px;
	int			size_line;
	int			endian;

	mlx->image = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_data = mlx_get_data_addr(mlx->image, &b_p_px, &size_line, &endian);
	draw_map(mlx);
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image, mlx->mv, mlx->up);
	mlx_destroy_image(mlx->ptr, mlx->image);
	return (0);
}

int				ft_map_maker(t_mlx *mlx)
{
	mlx->zoom = 1;
	mlx->mv = 0;
	mlx->up = 0;
	mlx->z = 0;
	mlx->projection = 0.5;
	if (!(mlx->ptr = mlx_init()))
		return (error_handler(MLX));
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "Fdf");
	mlx_key_hook(mlx->win, fdf_exit, mlx);
	mlx_hook(mlx->win, 2, 3, fdf_move, mlx);
	mlx_loop_hook(mlx->ptr, img_handler, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
