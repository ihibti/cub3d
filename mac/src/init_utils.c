/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:19:00 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/17 23:27:35 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'S')
		return (1);
	if (c == 'W')
		return (1);
	return (0);
}

int	init_pl(t_ori *ori)
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
			if (is_player(map[i][j]))
			{
				ori->player->x_map = j;
				ori->player->pos_x = (double)j + 0.5;
				ori->player->y_map = i;
				ori->player->pos_y = (double)i + 0.5;
				return (0);
			}
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
			if (map[i][j] == 'N')
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

	x = ori->player->x_map;
	y = ori->player->y_map;
	if (ori->map[y][x] == 'N')
		ori->player->dir_angle = M_PI / 2;
	else if (ori->map[y][x] == 'S')
		ori->player->dir_angle = (3 * M_PI) / 2;
	else if (ori->map[y][x] == 'E')
		ori->player->dir_angle = 0;
	else if (ori->map[y][x] == 'W')
		ori->player->dir_angle = M_PI;
	else
		printf("probleme\n");
	ori->player->x_map = x;
	ori->player->y_map = y;
	ori->map[y][x] = '0';
	printf("tout va bien\n");
}

// TODO : free ori pour juste return
int	check_init_p(t_ori *ori)
{
	t_player	*player;

	if (!ori || !ori->player || !ori->map)
		return (1);
	player = ori->player;
	if (player->pos_x == -1 || player->pos_y == -1)
		return (1);
	return (0);
}
