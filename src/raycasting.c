/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:22:17 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/28 15:03:34 by ihibti           ###   ########.fr       */
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
}

void	init_ray(t_player *player)
{
	t_ray	*ray;

	ray = player->ray;
	copy_play_ray(player);
	ray->dirangle = player->dir_angle + FOV;
	ray->dir_ray_x = cos(ray->dirangle);
	if (ray->dir_ray_x > 0)
		ray->stepx = 1;
	else
		ray->stepx = -1;
	ray->dir_ray_y = sin(ray->dirangle);
	if (ray->dir_ray_y > 0)
		ray->stepy = -1;
	else
		ray->stepy = 1;
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
	ray->calcX = ray->plane_posx;
	ray->calcY = ray->plane_posy;
}

// TODO calculer calc_offset car constante
// TODO peut etre modifier le 2 * fov
void	offset_ray(t_ray *ray, int x)
{
	if (x)
	{
		ray->dirangle = ray->dirangle + (2 * (FOV / SCREEN_W));
		ray->dir_ray_x = cos(ray->dirangle);
		ray->dir_ray_y = sin(ray->dirangle);
		ray->calcX = ray->calcX + (ray->plane_dirx / SCREEN_W);
		ray->calcY = ray->calcY + (ray->plane_diry / SCREEN_W);
		ray->delta_y = sqrt(1 + (ray->dir_ray_x * ray->dir_ray_x)
				/ (ray->dir_ray_y * ray->dir_ray_y));
		ray->delta_x = sqrt(1 + (ray->dir_ray_y * ray->dir_ray_y)
				/ (ray->dir_ray_x * ray->dir_ray_x));
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
	}
}

double	ray_len(t_ori *ori, t_player *player, int x)
{
	t_ray	*ray;

	ray = player->ray;
	offset_ray(ray, x);
}

int	raycasting(t_ori *ori)
{
	t_player	*player;
	t_ray		*ray;
	int			x;
	double		len_ray;

	player = ori->player;
	init_ray(player);
	x = 0;
	while (x < SCREEN_W)
	{
		ray_len(ori, player, x);
	}
	return (0);
}
