/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:43:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/29 14:38:38 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_firsttep(t_ray *ray)
{
	if (ray->dir_ray_x > 0)
	{
		ray->stepx = 1;
		ray->sideDistX = ((double)ray->mapX + 1.0 - ray->pos_rayX)
			* ray->delta_x;
	}
	else
	{
		ray->stepx = -1;
		ray->sideDistX = (ray->pos_rayX - (double)ray->mapX) * ray->delta_x;
	}
	if (ray->dir_ray_y > 0)
	{
		ray->stepy = -1;
		ray->sideDistY = (ray->pos_rayY - (double)ray->mapY) * ray->delta_y;
	}
	else
	{
		ray->stepy = 1;
		ray->sideDistY = ((double)ray->mapY + 1.0 - ray->pos_rayY)
			* ray->delta_y;
	}
	printf("ray dirx :%.5f, raydiry %.5f\n", ray->dir_ray_x, ray->dir_ray_y);
	printf("stepx:%d sidedistx %f\n", ray->stepx, ray->sideDistX);
	printf("stepy:%d sidedisty %f\n", ray->stepy, ray->sideDistY);
}

void	dda_alg(t_ori *ori, t_ray *ray)
{
	char	**map;

	map = ori->map;
	get_firsttep(ray);
	printf("delta x : %.5f deltay %.5f\n", ray->delta_x, ray->delta_y);
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
			ray->hit = 1;
	}
	if (ray->last_hit == 1)
	{
		ray->perp_dist = ray->sideDistY - ray->delta_y;
		ray->color = 1;
	}
	else
	{
		ray->color = 0;
		ray->perp_dist = ray->sideDistX - ray->delta_x;
	}
	printf("%f\n", ray->perp_dist);
}
