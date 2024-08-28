/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:41:51 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/28 20:03:05 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

char	**allocate_map(void)
{
	char	**map;
	char	*data[20];

	data[0] = "11111111111111111111";
	data[1] = "10000100000000100001";
	data[2] = "10000010000001000001";
	data[3] = "10000001111110000001";
	data[4] = "10000001000000000001";
	data[5] = "10000000100000000001";
	data[6] = "10000222200000000001";
	data[7] = "10000200000000000001";
	data[8] = "10002000002000000001";
	data[9] = "10002000000000000001";
	data[10] = "1000200000200000001";
	data[11] = "10000002000000000001";
	data[12] = "10000000000000000001";
	data[13] = "10000000000000000001";
	data[14] = "10000000000000000001";
	data[15] = "10000000000000000001";
	data[16] = "10000000000000000001";
	data[17] = "10000N00000000000001";
	data[18] = "10000000000000000001";
	data[19] = "11111111111111111111";
	map = (char **)malloc(22 * sizeof(char *));
	if (map == NULL)
	{
		perror("Erreur d'allocation de mémoire");
		return (NULL);
	}
	for (int i = 0; i < 21; i++)
	{
		map[i] = (char *)malloc(21 * sizeof(char));
		if (map[i] == NULL)
		{
			perror("Erreur d'allocation de mémoire");
			for (int j = 0; j < i; j++)
			{
				free(map[j]);
			}
			free(map);
			return (NULL);
		}
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			map[i][j] = data[i][j];
		}
		map[i][20] = '\0';
	}
	map[20] = 0;
	return (map);
}

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	init_player(t_ori *ori)
{
	ori->player->ray = malloc(sizeof(t_ray));
	if (!ori->player->ray)
		return (1);
	ori->player->pos_x = init_x_pl(ori);
	ori->player->pos_y = init_y_pl(ori);
	init_dirangle(ori);
	ori->player->dir_x = cos(ori->player->dir_angle);
	ori->player->dir_y = sin(ori->player->dir_angle);
	return (0);
}

int	init(t_ori *ori)
{
	ori->player = malloc(sizeof(t_player));
	ori->floor = RED;
	ori->sky = BLUE;
	ori->wall = BLACK;
	ori->recast = true;
	if (!ori->player)
		return (-1);
	ori->map = allocate_map();
	if (!ori->map)
		return (free(ori->player), -1);
	init_player(ori);
	if (check_init_p(ori))
		return (1);
	if (start_mlx(ori))
		return (1);
	return (0);
}
