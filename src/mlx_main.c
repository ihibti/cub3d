/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:38:43 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/28 16:57:05 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_win(t_ori *ori)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= SCREEN_W)
	{
		while (y <= SCREEN_H)
		{
			if (y < (SCREEN_H / 2))
				mlx_pixel_put(ori->mlxptr, ori->mlxwin, x, y, ori->sky);
			else
				mlx_pixel_put(ori->mlxptr, ori->mlxwin, x, y, ori->floor);
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int	start_mlx(t_ori *ori)
{
	ori->mlxptr = mlx_init();
	if (!ori->mlxptr)
		return (1);
	ori->mlxwin = mlx_new_window(ori->mlxptr, SCREEN_W, SCREEN_H, "cub3d");
	if (!ori->mlxwin)
		return (free(ori->mlxptr), 1);
	mlx_key_hook(ori->mlxwin, han_inp, ori);
	// mlx_hook(ori->mlxwin, 3, 2L, han_inp, ori);
	mlx_hook(ori->mlxwin, 17, 1, brexit, ori);
	mlx_loop_hook(ori->mlxptr, raycasting, ori);
	mlx_loop(ori->mlxptr);
	return (0);
}
