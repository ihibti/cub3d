/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:22:17 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/08 13:48:43 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_play_ray(t_player *player)
{
	t_ray	*ray;

	ray = player->ray;
	ray->pos_rayX = player->pos_x;
	ray->pos_rayY = player->pos_y;
	ray->mapX = player->x_map;
	ray->mapY = player->y_map;
	ray->hit = 0;
	ray->perp_dist = 0;
	ray->last_hit = 0;
	ray->color = 0;
	ray->dir_ray_x = player->dir_x;
	ray->dir_ray_y = player->dir_y;
}
// void	reset_ray(t_ray *ray, t_player *player)
// {
// 	ray->hit = 0;
// 	ray->perp_dist = 0;
// 	ray->last_hit = 0;
// 	ray->color = 0;
// 	ray->mapX = player->x_map;
// 	ray->mapY = player->y_map;
// 	ray->dir_ray_x = player->dir_x;
// 	ray->dir_ray_y = player->dir_y;
// }

void	init_ray(t_player *player, int x)
{
	t_ray	*ray;
	double	ratio;

	if (x > 0)
		ratio = (double)x / (double)SCREEN_W;
	else
		ratio = 0;
	copy_play_ray(player);
	ray = player->ray;
	ray->odd = true;
	ray->cameraX = (2.0 * (ratio)) - 1;
	ray->dir_ray_y = ray->dir_ray_y + (ray->plane_diry * ray->cameraX);
	ray->dir_ray_x = ray->dir_ray_x + (ray->plane_dirx * ray->cameraX);
	if (ray->dir_ray_x == 0)
		ray->delta_x = DBL_MAX;
	else
		ray->delta_x = fabs(1 / ray->dir_ray_x);
	if (ray->dir_ray_y == 0)
		ray->delta_y = DBL_MAX;
	else
		ray->delta_y = fabs(1 / ray->dir_ray_y);
}

void	draw_line(t_ray *ray, int x, t_ori *ori)
{
	int		line_h;
	int		drawstart;
	int		draw_end;
	int		y;
	double	ratio;
	double	i;
	int		wall;

	line_h = (int)((double)SCREEN_H / ray->perp_dist);
	ratio = 64 / (double)line_h;
	drawstart = (-line_h / 2) + (SCREEN_H / 2);
	draw_end = (line_h / 2) + (SCREEN_H / 2);
	y = 0;
	if (drawstart < 0)
		drawstart = 0;
	if (draw_end >= SCREEN_H)
		draw_end = SCREEN_H - 1;
	i = 0;
	if (ray->last_hit == 0)
		wall = 0;
	else
		wall = 1;
	while (y < drawstart)
		*((int *)ori->display.data + y++ * SCREEN_W + x) = BLUE;
	while (y < draw_end)
	{
		*((int *)ori->display.data + y * SCREEN_W
				+ x) = *((int *)ori->textures[wall].data + ray->coord_stripe
				+ (int)i * 64);
		i += ratio;
		++y;
	}
	while (y < SCREEN_H)
		*((int *)ori->display.data + y++ * SCREEN_W + x) = BROWN;
}

int	correction_close(t_player *player, t_ray *ray)
{
	double	delta_angle;

	if (ray->perp_dist < 0.3)
		ray->perp_dist = 0.3;
	delta_angle = atan2(ray->dir_ray_y, ray->dir_ray_x) - player->dir_angle;
	ray->perp_dist *= cos(delta_angle);
	if (ray->perp_dist < 0.1)
		ray->perp_dist = 0.1;
	return (0);
}

void	ray_len(t_ori *ori, t_player *player, int x)
{
	t_ray	*ray;

	ray = player->ray;
	init_ray(player, x);
	dda_alg(ori, ray, x);
	// if (ray->perp_dist < 0.4)
	// 	correction_close(player, ray);
	draw_line(ray, x, ori);
}

int	raycasting(t_ori *ori)
{
	t_player	*player;
	t_ray		*ray;
	int			x;

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
	mlx_put_image_to_window(ori->mlxptr, ori->mlxwin, ori->display.img, 0, 0);
	ori->recast = 0;
	return (0);
}
