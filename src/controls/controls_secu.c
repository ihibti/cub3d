/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_secu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/26 14:49:26 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
