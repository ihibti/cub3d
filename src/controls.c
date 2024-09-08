/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/08 12:04:27 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_a(t_ori *ori, t_player *player)
{
	double	new_x;
	double	new_y;
	double	left;

	left = player->dir_angle + (M_PI / 2);
	new_x = (MOVE_SPEED * cos(left)) + player->pos_x;
	new_y = player->pos_y - (MOVE_SPEED * sin(left));
	if (!move_unsafe(ori, player, new_x, new_y))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
		ori->recast = 1;
		player->x_map = (int)player->pos_x;
		player->y_map = (int)player->pos_y;
	}
	// raycasting(ori);
}

void	move_d(t_ori *ori, t_player *player)
{
	double	new_x;
	double	new_y;
	double	player_right;

	player_right = (player->dir_angle - (M_PI / 2));
	new_x = (MOVE_SPEED * cos(player_right)) + player->pos_x;
	new_y = player->pos_y - (MOVE_SPEED * sin(player_right));
	if (!move_unsafe(ori, player, new_x, new_y))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
		ori->recast = 1;
		player->x_map = (int)player->pos_x;
		player->y_map = (int)player->pos_y;
	}
	// raycasting(ori);
}

void	move_s(t_ori *ori, t_player *player)
{
	double	new_x;
	double	new_y;
	double	behind;

	behind = player->dir_angle + M_PI;
	new_x = player->pos_x + (MOVE_SPEED * cos(behind));
	new_y = player->pos_y - (MOVE_SPEED * sin(behind));
	if (!move_unsafe(ori, player, new_x, new_y))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
		ori->recast = 1;
		player->x_map = (int)player->pos_x;
		player->y_map = (int)player->pos_y;
	}
	// raycasting(ori);
}

void	move_w(t_ori *ori, t_player *player)
{
	double	new_x;
	double	new_y;
	double	front;

	front = player->dir_angle;
	new_x = player->pos_x + (MOVE_SPEED * (cos(front)));
	new_y = player->pos_y - (MOVE_SPEED * (sin(front)));
	if (!move_unsafe(ori, player, new_x, new_y))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
		player->x_map = (int)player->pos_x;
		player->y_map = (int)player->pos_y;
		ori->recast = 1;
		// raycasting(ori);
	}
}

int	move_unsafe(t_ori *ori, t_player *player, double new_x, double new_y)
{
	char	**map;

	map = ori->map;
	(void)player;
	if (map[(int)(new_y + 0.20)][(int)(new_x)] != '0')
		return (1);
	if (map[(int)(new_y - 0.20)][(int)(new_x)] != '0')
		return (1);
	if (map[(int)(new_y)][(int)(new_x + 0.20)] != '0')
		return (1);
	if (map[(int)(new_y)][(int)(new_x - 0.20)] != '0')
		return (1);
	if (map[(int)(new_y + 0.20)][(int)(new_x + 0.20)] != '0')
		return (1);
	if (map[(int)(new_y - 0.20)][(int)(new_x - 0.20)] != '0')
		return (1);
	if (map[(int)(new_y + 0.20)][(int)(new_x - 0.20)] != '0')
		return (1);
	if (map[(int)(new_y - 0.20)][(int)(new_x + 0.20)] != '0')
		return (1);
	if (map[(int)(new_y)][(int)(new_x)] != '0')
		return (1);
	return (0);
}

void	look_left(t_ori *ori)
{
	double	temp;

	temp = ori->player->dir_angle + CAMERA_SPEED;
	while (temp > ori->player->dir_angle)
	{
		ori->recast = 1;
		ori->player->dir_angle += PIXEL;
		ori->player->dir_x = cos(ori->player->dir_angle);
		ori->player->dir_y = sin(ori->player->dir_angle);
		// raycasting(ori);
	}
	if (ori->player->dir_angle > (2 * M_PI))
		ori->player->dir_angle -= 2 * M_PI;
	ori->player->dir_x = cos(ori->player->dir_angle);
	ori->player->dir_y = sin(ori->player->dir_angle);
	ori->recast = 1;
	// raycasting(ori);
}

void	look_right(t_ori *ori)
{
	// double	temp;
	ori->player->dir_angle = ori->player->dir_angle - CAMERA_SPEED;
	// while (temp < ori->player->dir_angle)
	// {
	// 	ori->player->dir_angle -= PIXEL;
	// 	ori->player->dir_x = cos(ori->player->dir_angle);
	// 	ori->player->dir_y = sin(ori->player->dir_angle);
	// 	raycasting(ori);
	// }
	if (ori->player->dir_angle < 0)
		ori->player->dir_angle += 2 * M_PI;
	ori->player->dir_x = cos(ori->player->dir_angle);
	ori->player->dir_y = sin(ori->player->dir_angle);
	ori->recast = 1;
	// raycasting(ori);
}

int	han_inp(int key, t_ori *ori)
{
	if (key == XK_Escape)
		brexit(ori);
	if (key == XK_w)
		move_w(ori, ori->player);
	if (key == XK_s)
		move_s(ori, ori->player);
	if (key == XK_d)
		move_d(ori, ori->player);
	if (key == XK_a)
		move_a(ori, ori->player);
	if (key == XK_Left)
		look_left(ori);
	if (key == XK_Right)
		look_right(ori);
	return (0);
}
