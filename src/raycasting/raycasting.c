/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:22:17 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/26 14:52:55 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycasting(t_ori *ori)
{
	t_player	*player;
	t_ray		*ray;
	int			x;

	truc_move(ori);
	player = ori->player;
	x = 0;
	ray = player->ray;
	ray->plane_dirx = sin(player->dir_angle) * FOV;
	ray->plane_diry = -cos(player->dir_angle) * FOV;
	while (x < SCREEN_W)
	{
		ray_len(ori, player, x);
		x++;
	}
	draw_minimap(ori);
	mlx_put_image_to_window(ori->mlxptr, ori->mlxwin, ori->display.img, 0, 0);
	ori->recast = 0;
	return (0);
}
