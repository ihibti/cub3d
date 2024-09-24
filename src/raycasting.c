/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:22:17 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/24 15:36:55 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			unsafe(int x, int y, char **map);

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
	if (drawstart < 0)
		drawstart = 0;
	if (draw_end >= SCREEN_H)
		draw_end = SCREEN_H - 1;
	if (ray->last_hit == 0)
	{
		if (ray->dir_ray_x > 0)
			wall = 0;
		else
			wall = 3;
	}
	else
	{
		if (ray->dir_ray_y > 0)
			wall = 1;
		else
			wall = 2;
	}
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
	if (unsafe(ori->player->x_map + stepx, ori->player->y_map + stepy, map))
		return (0);
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

int	unsafe(int x, int y, char **map)
{
	int	i;

	i = 0;
	if (x < 0 || y < 0)
		return (1);
        
	while (map[i])
		i++;
	if (y >= i)
		return (1);
	if (x >= ft_strlen(map[y]))
		return (1);
	return (0);
}

uint32_t	get_color_mini(int x, int y, char **map, t_ori *ori)
{
	if (unsafe(x, y, map))
		return (BLACK);
	if (x == ori->player->x_map && ori->player->y_map == y)
		return (RED);
	if (is_pov(x, y, ori))
		return (GREEN);
	if (map[y][x] == '0')
		return (WHITE);
	return (GRAY);
}

void	init_mnmap(int *i, int *j, t_ori *ori)
{
	*i = ori->player->x_map - 3;
	*j = ori->player->y_map - 3;
	if (*i < 0)
		*i = 0;
	if (*j < 0)
		i = 0;
}

void	draw_square(int x, int y, u_int32_t color, t_ori *ori)
{
	int	startx;
	int	starty;
	int	endx;
	int	endy;

	startx = (SCREEN_W / 28) * x;
	starty = (SCREEN_H / 28) * y;
	endx = startx + (SCREEN_W / 28);
	endy = starty + (SCREEN_H / 28);
	y = starty;
	while (startx < endx)
	{
		while (y <= endy)
		{
			*((int *)ori->display.data + startx + y * SCREEN_W) = color;
			y++;
		}
		y = starty;
		startx++;
	}
}

void	draw_minimap(t_ori *ori)
{
	char	**map;
	int		x;
	int		y;
	int		i;
	int		j;

	init_mnmap(&i, &j, ori);
	x = 0;
	y = 0;
	map = ori->map;
	while (x < 8)
	{
		while (y < 8)
		{
			draw_square(x, y, get_color_mini(i, j++, ori->map, ori), ori);
			y++;
		}
		i++;
		j -= 8;
		x++;
		y = 0;
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
	mlx_put_image_to_window(ori->mlxptr, ori->mlxwin, ori->display.img, 0, 0);
	ori->recast = 0;
	return (0);
}
