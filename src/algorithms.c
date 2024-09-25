/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:43:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/25 11:04:28 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_firsttep(t_ray *ray)
{
	if (ray->dir_ray_x < 0)
	{
		ray->stepx = -1;
		ray->sideDistX = (ray->pos_rayX - (double)ray->mapX) * ray->delta_x;
	}
	else
	{
		ray->stepx = 1;
		ray->sideDistX = ((double)ray->mapX + 1.0 - ray->pos_rayX)
			* ray->delta_x;
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
}

void	color_ray(t_ray *ray, t_ori *ori)
{
	if (ray->last_hit == 1)
	{
		if (ray->dir_ray_y > 0)
			ray->wall = &ori->textures[1];
		else
			ray->wall = &ori->textures[0];
		ray->perp_dist = ray->sideDistY - ray->delta_y;
		ray->color = 1;
		ray->wall_stripe = fabs(ray->pos_rayX + (ray->perp_dist
					* ray->dir_ray_x));
		ray->wall_stripe -= floor(ray->wall_stripe);
		ray->coord_stripe = (int)(ray->wall_stripe * ray->wall->width);
		if (ray->dir_ray_y > 0)
			ray->coord_stripe = ray->wall->width - ray->coord_stripe;
	}
	else
	{
		if (ray->dir_ray_x < 0)
			ray->wall = &ori->textures[2];
		else
			ray->wall = &ori->textures[3];
		ray->color = 0;
		ray->perp_dist = ray->sideDistX - ray->delta_x;
		ray->wall_stripe = fabs(ray->pos_rayY - (ray->perp_dist
					* ray->dir_ray_y));
		ray->wall_stripe -= floor(ray->wall_stripe);
		ray->coord_stripe = (int)(ray->wall_stripe * ray->wall->width);
		if (ray->dir_ray_x < 0)
			ray->coord_stripe = ray->wall->width - ray->coord_stripe;
	}
	if (ray->coord_stripe >= ray->wall->width)
		ray->coord_stripe = ray->wall->width - 1;
	if (ray->coord_stripe < 0)
		ray->coord_stripe = 0;
}

void	dda_alg(t_ori *ori, t_ray *ray, int x)
{
	char	**map;

	map = ori->map;
	get_firsttep(ray);
	(void)x;
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
		// TEST
		// Add boundary checks
		if (ray->mapY >= 0 && ray->mapY < ori->map_height && ray->mapX >= 0
			&& ray->mapX < ori->map_width)
		{
			if (map[ray->mapY][ray->mapX] != '0')
				ray->hit = 1;
		}
		else
		{
			// Outside map boundaries
			ray->hit = 1;
		}
		// END TEST; previous code:
		// if (map[ray->mapY][ray->mapX] != '0')
		// 	ray->hit = 1;
	}
	color_ray(ray, ori);
}
