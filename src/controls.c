/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/05 18:30:17 by ihibti           ###   ########.fr       */
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
	// printf("old x: %.10f new x %.10f\n", player->pos_x, new_x);
	// printf("old y: %.10f new y %.10f\n", player->pos_y, new_y);
	if (ori->map[(int)new_y][(int)(new_x)] == '0')
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
		ori->recast = 1;
		player->x_map = (int)player->pos_x;
		player->y_map = (int)player->pos_y;
	}
	raycasting(ori);
}

void	move_d(t_ori *ori, t_player *player)
{
	double	new_x;
	double	new_y;
	double	player_right;

	player_right = (player->dir_angle - (M_PI / 2));
	new_x = (MOVE_SPEED * cos(player_right)) + player->pos_x;
	new_y = player->pos_y - (MOVE_SPEED * sin(player_right));
	// printf("old x: %.10f new x %.10f\n", player->pos_x, new_x);
	// printf("old y: %.10f new y %.10f\n", player->pos_y, new_y);
	if (ori->map[(int)new_y][(int)(new_x)] == '0')
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
		ori->recast = 1;
		player->x_map = (int)player->pos_x;
		player->y_map = (int)player->pos_y;
	}
	raycasting(ori);
}

void	move_w(t_ori *ori, t_player *player)
{
	double	new_x;
	double	new_y;
	double	in_front;

	in_front = player->dir_angle;
	new_x = (MOVE_SPEED * cos(in_front)) + player->pos_x;
	new_y = player->pos_y - (MOVE_SPEED * sin(in_front));
	printf("old x: %.10f new x %.10f\n", player->pos_x, new_x);
	printf("old y: %.10f new y %.10f\n", player->pos_y, new_y);
	if (ori->map[(int)new_y][(int)(new_x)] == '0')
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
		ori->recast = 1;
		player->x_map = (int)player->pos_x;
		player->y_map = (int)player->pos_y;
	}
	raycasting(ori);
}

void	move_s(t_ori *ori, t_player *player)
{
	double	new_x;
	double	new_y;
	double	behind;

	behind = player->dir_angle + M_PI;
	new_x = (MOVE_SPEED * (cos(behind))) + player->pos_x;
	new_y = player->pos_y - (MOVE_SPEED * (sin(behind)));
	if (ori->map[(int)new_y][(int)(new_x)] == '0')
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
		player->x_map = (int)player->pos_x;
		player->y_map = (int)player->pos_y;
		ori->recast = 1;
		raycasting(ori);
	}
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
		raycasting(ori);
	}
	if (ori->player->dir_angle > (2 * M_PI))
		ori->player->dir_angle = 0;
	ori->player->dir_x = cos(ori->player->dir_angle);
	ori->player->dir_y = sin(ori->player->dir_angle);
	ori->recast = 1;
	raycasting(ori);
}

void	look_right(t_ori *ori)
{
	double	temp;

	temp = ori->player->dir_angle - CAMERA_SPEED;
	while (temp < ori->player->dir_angle)
	{
		ori->player->dir_angle -= PIXEL;
		ori->player->dir_x = cos(ori->player->dir_angle);
		ori->player->dir_y = sin(ori->player->dir_angle);
		raycasting(ori);
	}
	if (ori->player->dir_angle < 0)
		ori->player->dir_angle = 2 * M_PI;
	ori->player->dir_x = cos(ori->player->dir_angle);
	ori->player->dir_y = sin(ori->player->dir_angle);
	ori->recast = 1;
	raycasting(ori);
}

int	han_inp(int key, t_ori *ori)
{
	if (key == XK_Escape)
		brexit(ori);
	if (key == 'w')
		move_w(ori, ori->player);
	if (key == 's')
		move_s(ori, ori->player);
	if (key == 'd')
		move_d(ori, ori->player);
	if (key == 'a')
		move_a(ori, ori->player);
	if (key == XK_Left)
		look_left(ori);
	if (key == XK_Right)
		look_right(ori);
	return (0);
}
