/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/24 17:26:06 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		secu(t_ori *ori, t_player *s_player, double dir_m);
int		slide(t_ori *ori, t_player *player, double dir_m);
int		land_secu(t_ori *ori, t_player *player);

void	move_a(t_ori *ori, t_player *player)
{
	double	dir_m;
	double	new_x;
	double	new_y;

	dir_m = player->dir_angle + (M_PI / 2);
	new_y = player->pos_y - (MOVE_SPEED * (sin(dir_m)));
	new_x = player->pos_x + (MOVE_SPEED * (cos(dir_m)));
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
	new_y = player->pos_y - (MOVE_SPEED * (sin(dir_m)));
	new_x = player->pos_x + (MOVE_SPEED * (cos(dir_m)));
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
	new_y = player->pos_y - (MOVE_SPEED * (sin(dir_m)));
	new_x = player->pos_x + (MOVE_SPEED * (cos(dir_m)));
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

int	land_secu(t_ori *ori, t_player *player)
{
	char	**map;
	double	new_x;
	double	new_y;

	map = ori->map;
	new_x = player->pos_x;
	new_y = player->pos_y;
	if (map[(int)new_y][(int)new_x] == '0')
	{
		if (map[(int)(new_y + 0.2)][(int)new_x] != '0')
			player->pos_y = (double)((int)player->pos_y + 1) - 0.2;
		if (map[(int)(new_y - 0.2)][(int)new_x] != '0')
			player->pos_y = (double)((int)player->pos_y) + 0.2;
		if (map[(int)(new_y)][(int)(new_x - 0.2)] != '0')
			player->pos_x = (double)((int)player->pos_x) + 0.2;
		if (map[(int)(new_y)][(int)(new_x + 0.2)] != '0')
			player->pos_x = (double)((int)player->pos_x + 1) - 0.2;
	}
	return (0);
}

int	secu(t_ori *ori, t_player *player, double dir_m)
{
	char	**map;
	double	new_x;
	double	new_y;
	double	safetyx;
	double	safetyy;

	map = ori->map;
	safetyy = 0.2;
	safetyx = 0.2;
	if (cos(dir_m) < 0)
		safetyx = -0.2;
	if (sin(dir_m) > 0)
		safetyy = -0.2;
	new_x = player->pos_x + safetyx + (MOVE_SPEED * cos(dir_m));
	new_y = player->pos_y - (MOVE_SPEED * sin(dir_m)) + safetyy;
	if (map[(int)new_y][(int)new_x] != '0')
		return (1);
	return (0);
}

void	move_w(t_ori *ori, t_player *player)
{
	double	dir_m;
	double	new_x;
	double	new_y;

	dir_m = player->dir_angle;
	new_y = player->pos_y - (MOVE_SPEED * (sin(dir_m)));
	new_x = player->pos_x + (MOVE_SPEED * (cos(dir_m)));
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

int	corner_slide(t_ori *ori, t_player *player, double dir_m)
{
	// char	**map;
	double	new_x;
	double	new_y;

	// map = ori->map;
	new_x = player->pos_x;
	new_y = player->pos_y;
	if (fabs(sin(dir_m)) > fabs(cos(dir_m)))
	{
		slide_x(ori, player, dir_m);
		player->pos_y = player->pos_y - (MOVE_SPEED * sin(dir_m));
	}
	else
	{
		slide_y(ori, player, dir_m);
		player->pos_x = player->pos_x + (MOVE_SPEED * cos(dir_m));
	}
	return (0);
}

int	slide(t_ori *ori, t_player *player, double dir_m)
{
	char	**map;
	double	new_x;
	double	new_y;
	double	safetyx;
	double	safetyy;

	map = ori->map;
	safetyy = 0.2;
	safetyx = 0.2;
	if (cos(dir_m) < 0)
		safetyx = -0.2;
	if (sin(dir_m) > 0)
		safetyy = -0.2;
	new_x = player->pos_x + safetyx + (MOVE_SPEED * cos(dir_m));
	new_y = player->pos_y - (MOVE_SPEED * sin(dir_m)) + safetyy;
	if (map[(int)new_y][(int)player->pos_x] == '0'
		&& map[(int)player->pos_y][(int)new_x] == '0')
		corner_slide(ori, player, dir_m);
	else if (map[(int)new_y][(int)player->pos_x] == '0')
	{
		slide_x(ori, player, dir_m);
		player->pos_y = new_y - safetyy;
	}
	else if (map[(int)player->pos_y][(int)new_x] == '0')
	{
		slide_y(ori, player, dir_m);
		player->pos_x = new_x - safetyx;
	}
	else
	{
		slide_x(ori, player, dir_m);
		slide_y(ori, player, dir_m);
	}
	return (0);
}

int	slide_x(t_ori *ori, t_player *player, double dir_m)
{
	(void)ori;
	if (cos(dir_m) > 0)
		player->pos_x = (double)((int)player->pos_x + 1) - 0.2;
	else
		player->pos_x = (double)((int)player->pos_x) + 0.2;
	return (0);
}

int	slide_y(t_ori *ori, t_player *player, double dir_m)
{
	(void)ori;
	if (sin(dir_m) < 0)
		player->pos_y = (double)((int)player->pos_y + 1) - 0.2;
	else
		player->pos_y = (double)((int)player->pos_y) + 0.2;
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
	if (key == XK_Escape || key == XK_q)
		brexit(ori);
	if (key == XK_w)
		ori->w = true;
	if (key == XK_s)
		ori->s = true;
	if (key == XK_d)
		ori->d = true;
	if (key == XK_a)
		ori->a = true;
	if (key == XK_Left)
		ori->left = true;
	if (key == XK_Right)
		ori->right = true;
	return (0);
}

int	han_inp_release(int key, t_ori *ori)
{
	if (key == XK_Escape || key == XK_q)
		brexit(ori);
	if (key == XK_w)
		ori->w = false;
	if (key == XK_s)
		ori->s = false;
	if (key == XK_d)
		ori->d = false;
	if (key == XK_a)
		ori->a = false;
	if (key == XK_Left)
		ori->left = false;
	if (key == XK_Right)
		ori->right = false;
	return (0);
}
