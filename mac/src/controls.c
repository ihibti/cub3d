/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/17 20:50:47 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_a(t_ori *ori, t_player *player)
{
	double	dir_m;

	dir_m = player->dir_angle + (M_PI / 2);
	slide_x(ori, player, dir_m);
	slide_y(ori, player, dir_m);
	// raycasting(ori);
}

void	move_d(t_ori *ori, t_player *player)
{
	double	dir_m;

	dir_m = (player->dir_angle - (M_PI / 2));
	slide_x(ori, player, dir_m);
	slide_y(ori, player, dir_m);
	// raycasting(ori);
}

void	move_s(t_ori *ori, t_player *player)
{
	double	dir_m;

	dir_m = player->dir_angle + M_PI;
	slide_x(ori, player, dir_m);
	slide_y(ori, player, dir_m);
	// raycasting(ori);
}

void	move_w(t_ori *ori, t_player *player)
{
	double	dir_m;

	dir_m = player->dir_angle;
	slide_y(ori, player, dir_m);
	slide_x(ori, player, dir_m);
}

int	slide_x(t_ori *ori, t_player *player, double dir_m)
{
	char	**map;
	double	new_x;
	double	new_y;

	map = ori->map;
	new_y = player->pos_y - (MOVE_SPEED * (sin(dir_m)));
	new_x = player->pos_x + (MOVE_SPEED * (cos(dir_m)));
	if (cos(dir_m) > 0)
	{
		if (map[(int)new_y][(int)(new_x + 0.2)] == '0')
			player->pos_x = new_x;
		else
			player->pos_x = (double)((int)new_x + 1) - 0.2;
	}
	else
	{
		if (map[(int)(new_y)][(int)(new_x - 0.2)])
			player->pos_x = new_x;
		else
			player->pos_x = (double)((int)new_x) + 0.2;
	}
	player->x_map = (int)player->pos_x;
	return (0);
}

int	slide_y(t_ori *ori, t_player *player, double dir_m)
{
	char	**map;
	double	new_y;

	map = ori->map;
	new_y = player->pos_y - (MOVE_SPEED * (sin(dir_m)));
	if (sin(dir_m) > 0)
	{
		if (map[(int)(new_y - 0.2)][player->x_map] == '0')
			player->pos_y = new_y;
		else
			player->pos_y = (double)(player->y_map) + 0.2;
	}
	else
	{
		if (map[(int)(new_y + 0.2)][player->x_map] == '0')
			player->pos_y = new_y;
		else
			player->pos_y = (double)(player->y_map + 1) - 0.2;
	}
	player->y_map = (int)player->pos_y;
	return (0);
}

void	look_left(t_ori *ori)
{
	ori->player->dir_angle += (double)(CAMERA_SPEED / 10);
	if (ori->player->dir_angle > (2 * M_PI))
		ori->player->dir_angle -= 2 * M_PI;
	ori->player->dir_x = cos(ori->player->dir_angle);
	ori->player->dir_y = sin(ori->player->dir_angle);
	ori->recast = 1;
}

void	look_right(t_ori *ori)
{
	ori->player->dir_angle -= (double)(CAMERA_SPEED / 10);
	if (ori->player->dir_angle < 0)
		ori->player->dir_angle += 2 * M_PI;
	ori->player->dir_x = cos(ori->player->dir_angle);
	ori->player->dir_y = sin(ori->player->dir_angle);
	ori->recast = 1;
}

void	truc_move(t_ori *ori)
{
	if (ori->w)
		move_w(ori, ori->player);
	if (ori->a)
		move_a(ori, ori->player);
	if (ori->s)
		move_s(ori, ori->player);
	if (ori->d)
		move_d(ori, ori->player);
	if (ori->left)
		look_left(ori);
	if (ori->right)
		look_right(ori);
}
int	han_inp_press(int key, t_ori *ori)
{
	if (key == KEY_W)
		ori->w = true;
	if (key == KEY_S)
		ori->s = true;
	if (key == KEY_D)
		ori->d = true;
	if (key == KEY_A)
		ori->a = true;
	if (key == KEY_LEFT)
		ori->left = true;
	if (key == KEY_RIGHT)
		ori->right = true;
	return (0);
}

int	han_inp_release(int key, t_ori *ori)
{
	if (key == KEY_ESCAPE)
		brexit(ori);
	if (key == KEY_W)
		ori->w = false;
	if (key == KEY_S)
		ori->s = false;
	if (key == KEY_D)
		ori->d = false;
	if (key == KEY_A)
		ori->a = false;
	if (key == KEY_LEFT)
		ori->left = false;
	if (key == KEY_RIGHT)
		ori->right = false;
	return (0);
}
