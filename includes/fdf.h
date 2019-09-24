/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:40:24 by tigre             #+#    #+#             */
/*   Updated: 2019/02/22 19:44:51 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"

# define ARG 1
# define FD  2
# define MAP 3
# define MLC 4
# define MLX 5
# define WIDTH 2000
# define HEIGHT 1200

typedef struct		s_mlx
{
	int				h;
	int				w;
	int				**map;
	void			*ptr;
	void			*win;
	void			*image;
	char			*img_data;
	float			projection;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			z;
	int				mv;
	int				up;
	int				zoom;
}					t_mlx;

void				gen_map(t_mlx *mlx, char *name);
int					error_handler(int value);
int					ft_map_maker(t_mlx *mlx);
int					color(t_mlx *mlx, int x, int y);
void				put_px_image(int x, int y, t_mlx *mlx, int color);
int					fdf_move(int keycode, t_mlx *mlx);
int					fdf_exit(int key, t_mlx *mlx);
void				free_tabs(t_mlx *mlx);

#endif
