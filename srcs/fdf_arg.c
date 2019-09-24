/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:23:39 by ghtouman          #+#    #+#             */
/*   Updated: 2019/02/22 19:27:10 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_move(int keycode, t_mlx *mlx)
{
	if (keycode == 69 || keycode == 24)
	{
		mlx->zoom = mlx->zoom + 1;
		mlx->z = mlx->z + 0.1;
	}
	if (keycode == 78 || keycode == 27)
	{
		mlx->zoom = mlx->zoom - 1;
		mlx->z = mlx->z - 0.1;
	}
	(keycode == 35) ? mlx->projection = 2 : mlx->projection;
	(keycode == 15) ? mlx->zoom = 5 : mlx->zoom;
	(keycode == 15) ? mlx->mv = 0 : mlx->mv;
	(keycode == 15) ? mlx->up = 0 : mlx->up;
	(keycode == 15) ? mlx->z = 0 : mlx->z;
	(keycode == 34) ? mlx->projection = 0.5 : mlx->projection;
	(keycode == 6) ? mlx->z += 1 : mlx->z;
	(keycode == 7) ? mlx->z -= 1 : mlx->z;
	(keycode == 13 || keycode == 126) ? mlx->up -= 5 : mlx->up;
	(keycode == 1 || keycode == 125) ? mlx->up += 5 : mlx->up;
	(keycode == 0 || keycode == 123) ? mlx->mv -= 5 : mlx->mv;
	(keycode == 2 || keycode == 124) ? mlx->mv += 5 : mlx->mv;
	return (0);
}

void	put_px_image(int x, int y, t_mlx *mlx, int color)
{
	if ((x > 0 && y > 0) && (x <= WIDTH && y <= HEIGHT) && color == 1)
	{
		mlx->img_data[(x * 4) + (y * WIDTH * 4) + 1] = 0;
		mlx->img_data[(x * 4) + (y * WIDTH * 4) + 2] = 0;
		mlx->img_data[(x * 4) + (y * WIDTH * 4)] = -52;
	}
	else if ((x > 0 && y > 0) && (x <= WIDTH && y <= HEIGHT) && color == 2)
	{
		mlx->img_data[(x * 4) + (y * WIDTH * 4) + 2] = 15;
		mlx->img_data[(x * 4) + (y * WIDTH * 4) + 1] = -101;
		mlx->img_data[(x * 4) + (y * WIDTH * 4)] = 0;
	}
	else if ((x > 0 && y > 0) && (x <= WIDTH && y <= HEIGHT) && color == 3)
	{
		mlx->img_data[(x * 4) + (y * WIDTH * 4) + 2] = 81;
		mlx->img_data[(x * 4) + (y * WIDTH * 4) + 1] = 62;
		mlx->img_data[(x * 4) + (y * WIDTH * 4)] = 17;
	}
	else if ((x > 0 && y > 0) && (x <= WIDTH && y <= HEIGHT) && color == 4)
	{
		mlx->img_data[(x * 4) + (y * WIDTH * 4) + 1] = -6;
		mlx->img_data[(x * 4) + (y * WIDTH * 4) + 2] = -14;
		mlx->img_data[(x * 4) + (y * WIDTH * 4)] = -32;
	}
}

int		color(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x] <= 0)
		return (1);
	else if (mlx->map[y][x] > 0 && mlx->map[y][x] <= 30)
		return (2);
	else if (mlx->map[y][x] >= 31 && mlx->map[y][x] <= 110)
		return (3);
	else
		return (4);
}
