/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/28 20:30:59 by ihibti           ###   ########.fr       */
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
	raycasting(ori);
}

void	move_d(t_ori *ori, t_player *player)
{
	if (ori->map[(int)player->pos_y][(int)(player->pos_x + MOVE_SPEED)] == '0')
	{
		player->pos_x += MOVE_SPEED;
		ori->recast = true;
	}
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
	raycasting(ori);
}
void	move_s(t_ori *ori, t_player *player)
{
	if (ori->map[(int)(player->pos_y + MOVE_SPEED)][(int)player->pos_x] == '0')
	{
		player->pos_y += MOVE_SPEED;
		ori->recast = true;
	}
	raycasting(ori);
}

void	look_left(t_ori *ori)
{
	ori->player->dir_angle += CAMERA_SPEED;
	if (ori->player->dir_angle > (2 * M_PI))
		ori->player->dir_angle = 0;
	ori->recast = 1;
	raycasting(ori);
	ori->recast = 0;
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
	return (0);
}