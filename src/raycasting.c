/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:22:17 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/29 17:41:17 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_play_ray(t_player *player)
{
	t_ray	*ray;

	ray = player->ray;
	ray->pos_rayX = player->pos_x;
	ray->pos_rayY = player->pos_y;
	ray->mapX = (int)player->pos_x;
	ray->mapY = (int)player->pos_x;
	ray->hit = 0;
	ray->perp_dist = 0;
	ray->sideDistX = 0;
	ray->sideDistY = 0;
	ray->last_hit = 0;
	ray->sideDistX = 0;
	ray->sideDistY = 0;
	ray->color = 0;
	ray->dir_ray_x = cos(player->dir_angle);
	ray->dir_ray_y = sin(player->dir_angle);
}

void	init_ray(t_player *player, int x)
{
	t_ray	*ray;
	double	ratio;

	ratio = (double)x / (double)SCREEN_W;
	ray = player->ray;
	copy_play_ray(player);
	// printf("dirangle%f\n\n", player->dir_angle);
	ray->plane_dirx = -sin(player->dir_angle) * FOV;
	ray->plane_diry = cos(player->dir_angle) * FOV;
	ray->cameraX = (2.0 * (ratio)) - 1;
	ray->dir_ray_y = ray->dir_ray_y + (ray->plane_diry * ray->cameraX);
	ray->dir_ray_x = ray->dir_ray_x + (ray->plane_dirx * ray->cameraX);
	// printf("raydiry %.5f \n", ray->dir_ray_y);
	if (ray->dir_ray_x == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = fabs(1 / ray->dir_ray_x);
	if (ray->dir_ray_y == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = fabs(1 / ray->dir_ray_y);
}

// TODO calculer calc_offset car constante
// TODO peut etre modifier le 2 * fov
// void	offset_ray(t_ray *ray, int x, t_player *player)
// {
// 	if (x > 0)
// 	{
// 		ray->mapX = (int)player->pos_x;
// 		ray->mapY = (int)player->pos_y;
// 		ray->cameraX = 2 * x / SCREEN_H - 1;
// 		printf("camera x :%f", ray->cameraX);
// 		ray->dirangle = ray->dirangle - (FOV / SCREEN_W);
// 		ray->dir_ray_x = player->dir_x + ray->plane_dirx * ray->cameraX;
// 		ray->dir_ray_y = player->dir_y + ray->plane_diry * ray->cameraX;
// 		ray->delta_y = sqrt(1 + ((ray->dir_ray_x * ray->dir_ray_x)
// 					/ (ray->dir_ray_y * ray->dir_ray_y)));
// 		ray->delta_x = sqrt(1 + ((ray->dir_ray_y * ray->dir_ray_y)
// 					/ (ray->dir_ray_x * ray->dir_ray_x)));
// 		if (ray->dir_ray_x > 0)
// 			ray->stepx = 1;
// 		else
// 			ray->stepx = -1;
// 		if (ray->dir_ray_y > 0)
// 			ray->stepy = -1;
// 		else
// 			ray->stepy = 1;
// 		ray->sideDistX = 0;
// 		ray->sideDistY = 0;
// 		ray->perp_dist = 0;
// 		ray->last_hit = 0;
// 	}
// }

void	draw_line(t_ray *ray, int x, t_ori *ori)
{
	int	line_h;
	int	drawstart;
	int	draw_end;
	int	y;
	int	wall_c;

	line_h = (int)((double)SCREEN_H / ray->perp_dist);
	drawstart = (-line_h / 2) + (SCREEN_H / 2);
	draw_end = (line_h / 2) + (SCREEN_H / 2);
	y = SCREEN_H - 1;
	if (draw_end < 0)
		draw_end = SCREEN_H - 1;
	if (drawstart >= SCREEN_H)
		drawstart = SCREEN_H - 1;
	if (ray->color == 1)
		wall_c = YELLOW;
	else
		wall_c = RED;
	while (y > draw_end)
		mlx_pixel_put(ori->mlxptr, ori->mlxwin, x, y--, BLACK);
	while (y > drawstart)
		mlx_pixel_put(ori->mlxptr, ori->mlxwin, x, y--, wall_c);
	while (y > 0)
		mlx_pixel_put(ori->mlxptr, ori->mlxwin, x, y--, BLUE);
}

void	ray_len(t_ori *ori, t_player *player, int x)
{
	t_ray	*ray;

	ray = player->ray;
	init_ray(player, x);
	dda_alg(ori, ray);
	draw_line(ray, x, ori);
}

int	raycasting(t_ori *ori)
{
	t_player	*player;
	t_ray		*ray;
	int			x;
	int			i;
	int			y;

	player = ori->player;
	x = 0;
	ray = player->ray;
	// printf("%c%c%c\n", ori->map[player->y_map - 1][player->x_map - 1],
	// 	ori->map[player->y_map - 1][player->x_map], ori->map[player->y_map
	// 	- 1][player->x_map + 1]);
	// printf("%c%c%c\n", ori->map[player->y_map][player->x_map - 1],
	// 	ori->map[player->y_map][player->x_map],
	// 	ori->map[player->y_map][player->x_map + 1]);
	// printf("%c%c%c\n", ori->map[player->y_map + 1][player->x_map - 1],
	// 	ori->map[player->y_map + 1][player->x_map], ori->map[player->y_map
	// + 1][player->x_map + 1]);
	i = 0;
	y = 0;
	while (ori->map[i])
	{
		if (i == (int)player->pos_y)
		{
			while (y++ < (int)player->pos_x)
				printf(" ");
			printf("player\n");
		}
		printf("%s\n", ori->map[i++]);
	}
	printf("x:%f y:%f\n", player->pos_x, player->pos_y);
	while (x < SCREEN_W)
	{
		ray_len(ori, player, x);
		x++;
	}
	return (0);
}
