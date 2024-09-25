/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:38:43 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/25 16:32:34 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_ori *ori)
{
	ori->mlxptr = mlx_init();
	if (!ori->mlxptr)
		brexit(ori);
}

static void	init_mlx_window(t_ori *ori)
{
	ori->mlxwin = mlx_new_window(ori->mlxptr, SCREEN_W, SCREEN_H, "cub3D");
	if (!ori->mlxwin)
		brexit(ori);
	ori->display.img = mlx_new_image(ori->mlxptr, SCREEN_W, SCREEN_H);
	if (!ori->display.img)
		brexit(ori);
	ori->display.data = mlx_get_data_addr(ori->display.img, &ori->display.bpp,
			&ori->display.width, &ori->display.height);
	if (!ori->display.data)
		brexit(ori);
}

static void	mlx_hooks(t_ori *ori)
{
	mlx_hook(ori->mlxwin, 3, 2L, han_inp_release, ori);
	mlx_hook(ori->mlxwin, 2, 1L, han_inp_press, ori);
	mlx_hook(ori->mlxwin, 17, 1, brexit, ori);
	mlx_loop_hook(ori->mlxptr, raycasting, ori);
	mlx_loop(ori->mlxptr);
}

int	start_mlx(t_ori *ori)
{
	ori->recast = 1;
	init_mlx_window(ori);
	mlx_hooks(ori);
	return (0);
}
