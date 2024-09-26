/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:43:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/26 16:26:53 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_firsttep(t_ray *ray)
{
	if (ray->dir_ray_x < 0)
	{
		ray->stepx = -1;
		ray->side_distx = (ray->pos_ray_x - (double)ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->stepx = 1;
		ray->side_distx = ((double)ray->map_x + 1.0 - ray->pos_ray_x)
			* ray->delta_x;
	}
	if (ray->dir_ray_y > 0)
	{
		ray->stepy = -1;
		ray->side_disty = (ray->pos_ray_y - (double)ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->stepy = 1;
		ray->side_disty = ((double)ray->map_y + 1.0 - ray->pos_ray_y)
			* ray->delta_y;
	}
}

void	color_ray_1(t_ray *ray, t_ori *ori)
{
	if (ray->dir_ray_y > 0)
		ray->wall = &ori->textures[1];
	else
		ray->wall = &ori->textures[0];
	ray->perp_dist = ray->side_disty - ray->delta_y;
	ray->color = 1;
	ray->wall_stripe = fabs(ray->pos_ray_x + (ray->perp_dist * ray->dir_ray_x));
	ray->wall_stripe -= floor(ray->wall_stripe);
	ray->coord_stripe = (int)(ray->wall_stripe * ray->wall->width);
	if (ray->dir_ray_y > 0)
		ray->coord_stripe = ray->wall->width - ray->coord_stripe;
}

void	color_ray_0(t_ray *ray, t_ori *ori)
{
	if (ray->dir_ray_x < 0)
		ray->wall = &ori->textures[2];
	else
		ray->wall = &ori->textures[3];
	ray->color = 0;
	ray->perp_dist = ray->side_distx - ray->delta_x;
	ray->wall_stripe = fabs(ray->pos_ray_y - (ray->perp_dist * ray->dir_ray_y));
	ray->wall_stripe -= floor(ray->wall_stripe);
	ray->coord_stripe = (int)(ray->wall_stripe * ray->wall->width);
	if (ray->dir_ray_x < 0)
		ray->coord_stripe = ray->wall->width - ray->coord_stripe;
}

void	color_ray(t_ray *ray, t_ori *ori)
{
	if (ray->last_hit == 1)
		color_ray_1(ray, ori);
	else
		color_ray_0(ray, ori);
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
		if (ray->side_distx < ray->side_disty)
		{
			ray->side_distx += ray->delta_x;
			ray->map_x += ray->stepx;
			ray->last_hit = 0;
		}
		else
		{
			ray->side_disty += ray->delta_y;
			ray->map_y += ray->stepy;
			ray->last_hit = 1;
		}
		if (map[ray->map_y][ray->map_x] != '0')
			ray->hit = 1;
	}
	color_ray(ray, ori);
}
