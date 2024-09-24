/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_slide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/24 17:26:06 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	corner_slide(t_ori *ori, t_player *player, double dir_m)
{
	// char	**map;
	double	new_x;
	double	new_y;

	(void)new_x;	//jsp pq jpeux pas compile avec chez wam
	(void)new_y;	//jsp pq jpeux pas compile avec chez wam
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
