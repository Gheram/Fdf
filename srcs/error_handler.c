/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:18:05 by tigre             #+#    #+#             */
/*   Updated: 2019/02/22 19:38:55 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	error_handler(int value)
{
	if (value == ARG)
		write(1, "Usage : ./fdf <filename> [ case_size z_size ]\n", 46);
	if (value == FD)
		write(1, "The opening of the file failed\n", 31);
	if (value == MAP)
		write(1, "Found wrong line length. Exiting.\n", 34);
	if (value == MLC)
		write(1, "The malloc fail try again.\n", 27);
	if (value == MLX)
		write(1, "Mlx has crash.\n", 15);
	exit(value);
	return (0);
}
