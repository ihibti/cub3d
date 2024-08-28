/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:22:17 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/28 20:29:48 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_play_ray(t_player *player)
{
	t_ray	*ray;

	ray = player->ray;
	ray->pos_rayX = player->pos_x;
	ray->pos_rayY = player->pos_y;
	ray->hit = 0;
	ray->perp_dist = 0;
	ray->sideDistX = 0;
	ray->sideDistY = 0;
	ray->mapX = (int)ray->pos_rayX;
	ray->mapY = (int)ray->pos_rayY;
	ray->last_hit = 0;
	ray->sideDistX = 0;
	ray->sideDistY = 0;
	ray->last_hit = 0;
}

void	init_ray(t_player *player)
{
	t_ray	*ray;

	ray = player->ray;
	copy_play_ray(player);
	ray->dirangle = player->dir_angle + (FOV / 2);
	ray->dir_ray_x = cos(ray->dirangle);
	ray->plane_posx = player->pos_x + (cos(player->dir_angle + (M_PI / 2))
			* 0.25f);
	ray->plane_posy = player->pos_y - (sin(player->dir_angle + (M_PI / 2))
			* 0.25f);
	ray->delta_y = sqrt(1 + (ray->dir_ray_x * ray->dir_ray_x) / (ray->dir_ray_y
				* ray->dir_ray_y));
	ray->delta_x = sqrt(1 + (ray->dir_ray_y * ray->dir_ray_y) / (ray->dir_ray_x
				* ray->dir_ray_x));
	ray->plane_angle = player->dir_angle - (M_PI / 2);
	ray->plane_dirx = cos(ray->plane_angle);
	ray->plane_diry = sin(ray->plane_angle);
	ray->mapX = (int)ray->pos_rayX;
	ray->mapY = (int)ray->pos_rayY;
	ray->cameraX = 0;
	ray->dir_ray_x = player->dir_x + ray->plane_dirx * ray->cameraX;
	ray->dir_ray_y = player->dir_y + ray->plane_diry * ray->cameraX;
}

// TODO calculer calc_offset car constante
// TODO peut etre modifier le 2 * fov
void	offset_ray(t_ray *ray, int x, t_player *player)
{
	if (x > 0)
	{
		ray->cameraX = 2 * x / SCREEN_H - 1;
		ray->dirangle = ray->dirangle - (FOV / SCREEN_W);
		ray->dir_ray_x = player->dir_x + ray->plane_dirx * ray->cameraX;
		ray->dir_ray_y = player->dir_y + ray->plane_diry * ray->cameraX;
		ray->delta_y = sqrt(1 + ((ray->dir_ray_x * ray->dir_ray_x)
					/ (ray->dir_ray_y * ray->dir_ray_y)));
		ray->delta_x = sqrt(1 + ((ray->dir_ray_y * ray->dir_ray_y)
					/ (ray->dir_ray_x * ray->dir_ray_x)));
		if (ray->dir_ray_x > 0)
			ray->stepx = 1;
		else
			ray->stepx = -1;
		if (ray->dir_ray_y > 0)
			ray->stepy = -1;
		else
			ray->stepy = 1;
		ray->sideDistX = 0;
		ray->sideDistY = 0;
		ray->perp_dist = 0;
		ray->last_hit = 0;
		ray->mapX = (int)player->pos_x;
		ray->mapY = (int)player->pos_y;
	}
}

void	ray_len(t_ori *ori, t_player *player, int x)
{
	t_ray	*ray;

	ray = player->ray;
	offset_ray(ray, x, player);
	dda_alg(ori, ray);
}

int	raycasting(t_ori *ori)
{
	t_player	*player;
	t_ray		*ray;
	int			x;
	int			y;

	player = ori->player;
	init_ray(player);
	x = 0;
	ray = player->ray;
	y = 0;
	while (x < SCREEN_W)
	{
		ray_len(ori, player, x);
		while (y < SCREEN_H)
		{
			if ((ray->perp_dist) * 2 > y)
				mlx_pixel_put(ori->mlxptr, ori->mlxwin, x, y, ori->wall);
			else
				mlx_pixel_put(ori->mlxptr, ori->mlxwin, x, y, ori->sky);
			y++;
		}
		x++;
		y = 0;
	}
	return (0);
}
