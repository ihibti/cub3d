/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:38:43 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/14 19:57:21 by ihibti           ###   ########.fr       */
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
	ori->recast = 1;
	if (!ori->mlxptr)
		return (1);
	ori->mlxwin = mlx_new_window(ori->mlxptr, SCREEN_W, SCREEN_H, "cub3d");
	if (!ori->mlxwin)
		return (free(ori->mlxptr), 1);
	ori->textures[0].img = mlx_xpm_file_to_image(ori->mlxptr,
			"textures/eagle.xpm", &ori->textures[0].width,
			&ori->textures[0].height);
	ori->textures[1].img = mlx_xpm_file_to_image(ori->mlxptr,
			"textures/colorstone.xpm", &ori->textures[1].width,
			&ori->textures[1].height);
	ori->display.img = mlx_new_image(ori->mlxptr, SCREEN_W, SCREEN_H);
	ori->display.data = mlx_get_data_addr(ori->display.img, &ori->display.bpp,
			&ori->display.width, &ori->display.height);
	ori->textures[0].data = mlx_get_data_addr(ori->textures[0].img,
			&ori->textures[0].bpp, &ori->textures[0].width,
			&ori->textures[0].height);
	ori->textures[1].data = mlx_get_data_addr(ori->textures[1].img,
			&ori->textures[1].bpp, &ori->textures[1].width,
			&ori->textures[1].height);
	// mlx_hook(ori->mlxptr,han_inp,)
	// mlx_key_hook(ori->mlxwin, han_inp, ori);
	mlx_hook(ori->mlxwin, 3, 2L, han_inp_release, ori);
	mlx_hook(ori->mlxwin, 2, 1L, han_inp_press, ori);
	mlx_hook(ori->mlxwin, 17, 1, brexit, ori);
	mlx_loop_hook(ori->mlxptr, raycasting, ori);
	mlx_loop(ori->mlxptr);
	return (0);
}
