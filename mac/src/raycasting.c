/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:22:17 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/20 22:19:55 by ihibti           ###   ########.fr       */
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
	if (line_h < SCREEN_H)
		i = 0;
	else
		i = ratio * (line_h - SCREEN_H) / 2;
	drawstart = (-line_h / 2) + (SCREEN_H / 2);
	draw_end = (line_h / 2) + (SCREEN_H / 2);
	y = 0;
	if (ray->coord_stripe > 63)
		ray->coord_stripe = 63.0;
	if (drawstart < 0)
		drawstart = 0;
	if (draw_end >= SCREEN_H)
		draw_end = SCREEN_H - 1;
	if (ray->last_hit == 0)
		wall = 0;
	else
		wall = 1;
	while (y < drawstart && y < SCREEN_H)
		*((int *)ori->display.data + y++ * SCREEN_W + x) = BLUE;
	while (y <= draw_end && y < SCREEN_H)
	{
		*((int *)ori->display.data + y * SCREEN_W
				+ x) = *((int *)ori->textures[wall].data + ray->coord_stripe
				+ (int)(i)*64);
		i += ratio;
		if (i > 63)
			i = 63.0;
		y++;
	}
	while (y < SCREEN_H)
		*((int *)ori->display.data + y++ * SCREEN_W + x) = BROWN;
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

int	collision(char **map, t_ori *ori, int stepx, int stepy)
{
	if (stepx == 0 || stepy == 0)
		return (1);
	if (map[ori->player->y_map + stepy][ori->player->x_map] != '0')
	{
		if (map[ori->player->y_map][ori->player->x_map + stepx] != '0')
			return (0);
	}
	return (1);
}

int	is_pov(int x, int y, t_ori *ori)
{
	int		stepx;
	int		stepy;
	double	angle;

	angle = ori->player->dir_angle;
	if (cos(angle) > 0.5)
		stepx = 1;
	else if (cos(angle) < -0.5)
		stepx = -1;
	else
		stepx = 0;
	if (sin(angle) > 0.5)
		stepy = -1;
	else if (sin(angle) < -0.5)
		stepy = 1;
	else
		stepy = 0;
	if (x != ori->player->x_map + stepx || y != ori->player->y_map + stepy)
		return (0);
	if (ori->map[ori->player->y_map + stepy][ori->player->x_map + stepx] == '0')
		if (collision(ori->map, ori, stepx, stepy))
			return (1);
	return (0);
}

uint32_t	get_color_mini(int x, int y, char **map, t_ori *ori)
{
	int	x_max;
	int	y_max;
	int	i;
	int	j;

	map_dimensions(&x_max, &y_max, map);
	i = (int)((double)x / (((double)SCREEN_H / 4.0) / (double)x_max));
	j = (int)((double)y / (((double)SCREEN_H / 4.0) / (double)y_max));
	if (i == ori->player->x_map && ori->player->y_map == j)
		return (RED);
	if (is_pov(i, j, ori))
		return (GREEN);
	if (map[j][i] == '0')
		return (WHITE);
	if (i == x_max - 1 || j == y_max - 1)
		return (BLACK);
	if (i == 0 || j == 0)
		return (BLACK);
	return (GRAY);
}

void	drawEnemy(t_ori *ori, t_player *player, t_display *screen)
{
	float	dx;
	float	dy;
	float	distance;
	float	angle;
	int		screenX;
	int		screenY;
	int		spriteHeight;

	// Calculate angle and distance to enemy
	dx = 10 - player->pos_x;
	dy = 5 + player->pos_y;
	distance = sqrt(dx * dx + dy * dy);
	angle = atan2(dy, dx) - player->dir_angle;
	// Adjust angle to be within FOV
	if (angle < -M_PI)
		angle += 2 * M_PI;
	if (angle > M_PI)
		angle -= 2 * M_PI;
    printf("verdict >%f\n",angle);
	// Check if enemy is in view
	if (fabs(angle) > FOV / 2)
		return ;
	// Calculate screen position
	screenX = (angle + FOV / 2) / FOV * SCREEN_W;
	screenY = SCREEN_H / 2;
	// Calculate enemy height on screen
	spriteHeight = (int)(SCREEN_H / distance);
    printf("screenX:%d,screeny:%d,spriteheight:%d\n",screenX,screenY,spriteHeight);
	for (int i = screenX; i < spriteHeight+screenX && i < SCREEN_W; i++)
	{
		for (int j = screenY; j < spriteHeight+screenY && j < SCREEN_H; j++)
		{
			*((int *)screen->data + i + j * SCREEN_W) = YELLOW;
		}
	}
    printf("success\n");
}

void	draw_minimap(t_ori *ori)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = ori->map;
	while (x < (int)(SCREEN_H / 4))
	{
		while (y < (int)(SCREEN_H / 4))
		{
			*((int *)ori->display.data + y * SCREEN_W + x) = get_color_mini(x,
																			y,
																			map,
																			ori);
			y++;
		}
		y = 0;
		x++;
	}
}

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
	drawEnemy(ori, ori->player, &ori->display);
	mlx_put_image_to_window(ori->mlxptr, ori->mlxwin, ori->display.img, 0, 0);
	ori->recast = 0;
	return (0);
}
