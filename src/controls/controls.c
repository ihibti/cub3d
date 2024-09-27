/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/27 13:32:29 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_a(t_ori *ori, t_player *player)
{
	double	dir_m;
	double	new_x;
	double	new_y;

	dir_m = player->dir_angle + (M_PI / 2);
	new_y = player->pos_y - (ori->movespeed * (sin(dir_m)));
	new_x = player->pos_x + (ori->movespeed * (cos(dir_m)));
	if (!secu(ori, player, dir_m))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
	else
		slide(ori, player, dir_m);
	land_secu(ori, player);
	player->x_map = (int)player->pos_x;
	player->y_map = (int)player->pos_y;
}

void	move_d(t_ori *ori, t_player *player)
{
	double	dir_m;
	double	new_x;
	double	new_y;

	dir_m = (player->dir_angle - (M_PI / 2));
	new_y = player->pos_y - (ori->movespeed * (sin(dir_m)));
	new_x = player->pos_x + (ori->movespeed * (cos(dir_m)));
	if (!secu(ori, player, dir_m))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
	else
		slide(ori, player, dir_m);
	land_secu(ori, player);
	player->x_map = (int)player->pos_x;
	player->y_map = (int)player->pos_y;
}

void	move_s(t_ori *ori, t_player *player)
{
	double	dir_m;
	double	new_x;
	double	new_y;

	dir_m = player->dir_angle + M_PI;
	new_y = player->pos_y - (ori->movespeed * (sin(dir_m)));
	new_x = player->pos_x + (ori->movespeed * (cos(dir_m)));
	if (!secu(ori, player, dir_m))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
	else
		slide(ori, player, dir_m);
	land_secu(ori, player);
	player->x_map = (int)player->pos_x;
	player->y_map = (int)player->pos_y;
}

void	move_w(t_ori *ori, t_player *player)
{
	double	dir_m;
	double	new_x;
	double	new_y;

	dir_m = player->dir_angle;
	new_y = player->pos_y - (ori->movespeed * (sin(dir_m)));
	new_x = player->pos_x + (ori->movespeed * (cos(dir_m)));
	if (!secu(ori, player, dir_m))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
	else
		slide(ori, player, dir_m);
	land_secu(ori, player);
	player->x_map = (int)player->pos_x;
	player->y_map = (int)player->pos_y;
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
