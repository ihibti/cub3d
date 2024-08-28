/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:19:00 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/28 19:32:26 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_x_pl(t_ori *ori)
{
	char	**map;
	int		i;
	int		j;

	map = ori->map;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] == 'N')
				return (j);
			j++;
		}
		i++;
		j = 0;
	}
	return (-1);
}

int	init_y_pl(t_ori *ori)
{
	char	**map;
	int		i;
	int		j;

	map = ori->map;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] == 'N')
				return (i);
			j++;
		}
		i++;
		j = 0;
	}
	return (-1);
}

void	init_dirangle(t_ori *ori)
{
	int	x;
	int	y;

	x = ori->player->pos_x;
	y = ori->player->pos_y;
	if (ori->map[y][x] == 'N')
		ori->player->dir_angle = M_PI / 2;
	if (ori->map[y][x] == 'S')
		ori->player->dir_angle = (3 * M_PI) / 2;
	if (ori->map[y][x] == 'E')
		ori->player->dir_angle = 0;
	if (ori->map[y][x] == 'W')
		ori->player->dir_angle = M_PI;
}

// TODO : free ori pour juste return
int	check_init_p(t_ori *ori)
{
	t_player *player;

	if (!ori || !ori->player || !ori->map)
		return (1);
	player = ori->player;
	if (player->pos_x == -1 || player->pos_y == -1)
		return (1);
	return (0);
}