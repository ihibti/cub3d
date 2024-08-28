/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:43:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/28 20:37:06 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_firsttep(t_ray *ray)
{
	if (ray->dir_ray_x > 0)
		ray->sideDistX = (ray->mapX + 1.0 - ray->pos_rayX) * ray->delta_x;
	else
		ray->sideDistX = (ray->pos_rayX - ray->mapX) * ray->delta_x;
	if (ray->dir_ray_y > 0)
		ray->sideDistY = (ray->mapY + 1.0 - ray->pos_rayY) * ray->delta_y;
	else
		ray->sideDistY = (ray->pos_rayY - ray->mapY) * ray->delta_y;
}

void	dda_alg(t_ori *ori, t_ray *ray)
{
	char	**map;

	map = ori->map;
	if (!ray->dir_ray_x)
		ray->delta_x = 1e30;
	if (!ray->dir_ray_y)
		ray->delta_y = 1e30;
	get_firsttep(ray);
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->delta_x;
			ray->mapX += ray->stepx;
			ray->last_hit = 0;
		}
		else
		{
			ray->sideDistY += ray->delta_y;
			ray->mapY += ray->stepy;
			ray->last_hit = 1;
		}
		if (map[ray->mapY][ray->mapX] != '0')
		{
			ray->hit = 1;
		}
	}
	if (ray->last_hit)
		ray->perp_dist = ray->sideDistY - ray->delta_y;
	else
		ray->perp_dist = ray->sideDistX - ray->delta_x;
	printf("taille rayon:%f\n", ray->perp_dist);
	if (ray->perp_dist > SCREEN_H)
		ray->perp_dist = SCREEN_H - 20;
	if (ray->perp_dist < 0)
		ray->perp_dist = 20;
}
