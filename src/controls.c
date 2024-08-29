/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/29 11:30:30 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_a(t_ori *ori, t_player *player)
{
	if (ori->map[(int)player->pos_y][(int)(player->pos_x - MOVE_SPEED)] == '0')
	{
		player->pos_x -= MOVE_SPEED;
		ori->recast = true;
	}
	player->x_map = (int)player->pos_x;
	raycasting(ori);
}

void	move_d(t_ori *ori, t_player *player)
{
	if (ori->map[(int)player->pos_y][(int)(player->pos_x + MOVE_SPEED)] == '0')
	{
		player->pos_x += MOVE_SPEED;
		ori->recast = true;
	}
	player->x_map = (int)player->pos_x;
	raycasting(ori);
}
void	move_w(t_ori *ori, t_player *player)
{
	if (ori->map[(int)(player->pos_y
			- MOVE_SPEED)][(int)(player->pos_x)] == '0')
	{
		player->pos_y -= MOVE_SPEED;
		ori->recast = true;
	}
	player->y_map = (int)player->pos_y;
	raycasting(ori);
}
void	move_s(t_ori *ori, t_player *player)
{
	if (ori->map[(int)(player->pos_y + MOVE_SPEED)][(int)player->pos_x] == '0')
	{
		player->pos_y += MOVE_SPEED;
		ori->recast = true;
	}
	player->y_map = (int)player->pos_y;
	raycasting(ori);
}

void	look_left(t_ori *ori)
{
	ori->player->dir_angle += CAMERA_SPEED;
	if (ori->player->dir_angle > (2 * M_PI))
		ori->player->dir_angle = 0;
	ori->recast = 1;
	raycasting(ori);
}

void	look_right(t_ori *ori)
{
	ori->player->dir_angle -= CAMERA_SPEED;
	if (ori->player->dir_angle < 0)
		ori->player->dir_angle = 2 * M_PI;
	ori->recast = 1;
	raycasting(ori);
}

int	han_inp(int key, t_ori *ori)
{
	if (key == 'e')
		brexit(ori);
	if (key == 'w')
		move_w(ori, ori->player);
	if (key == 's')
		move_s(ori, ori->player);
	if (key == 'd')
		move_d(ori, ori->player);
	if (key == 'a')
		move_a(ori, ori->player);
	if (key == 'l')
		look_left(ori);
	if (key == 'p')
		look_right(ori);
	return (0);
}