/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:38:43 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/26 16:55:07 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_ori *ori)
{
	ori->mlxptr = mlx_init();
	if (!ori->mlxptr)
		brexit(ori, NULL);
}

static void	init_mlx_window(t_ori *ori)
{
	ori->mlxwin = mlx_new_window(ori->mlxptr, SCREEN_W, SCREEN_H, SCREEN_NAME);
	if (!ori->mlxwin)
		brexit(ori, NULL);
	ori->display.img = mlx_new_image(ori->mlxptr, SCREEN_W, SCREEN_H);
	if (!ori->display.img)
		brexit(ori, NULL);
	ori->display.data = mlx_get_data_addr(ori->display.img, &ori->display.bpp,
			&ori->display.width, &ori->display.height);
	if (!ori->display.data)
		brexit(ori, NULL);
}

static void	mlx_hooks(t_ori *ori)
{
	mlx_hook(ori->mlxwin, 3, 2L, han_inp_release, ori);
	mlx_hook(ori->mlxwin, 2, 1L, han_inp_press, ori);
	mlx_hook(ori->mlxwin, 17, 1, brexit, ori);
	mlx_hook(ori->mlxwin, MotionNotify, PointerMotionMask, han_mouse_move, ori);
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
