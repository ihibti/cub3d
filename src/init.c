/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:41:51 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/28 12:22:15 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

char	**allocate_map(void)
{
	char	**map;
	char	*data[8];

	data[0] = "11111111";
	data[1] = "11110001";
	data[2] = "10111001";
	data[3] = "10001001";
	data[4] = "10000001";
	data[5] = "10000001";
	data[6] = "1000E001";
	data[7] = "11111111";
	map = (char **)malloc(9 * sizeof(char *));
	if (map == NULL)
	{
		perror("Erreur d'allocation de mémoire");
		return (NULL);
	}
	for (int i = 0; i < 8; i++)
	{
		map[i] = (char *)malloc(9 * sizeof(char));
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
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			map[i][j] = data[i][j];
		}
		map[i][8] = '\0';
	}
	map[8] = 0;
	return (map);
}

void	free_map(char **map)
{
	if (map == NULL)
		return ;
	for (int i = 0; i < 8; i++)
	{
		free(map[i]);
	}
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
	if (!ori->player)
		return (-1);
	ori->map = allocate_map();
	if (!ori->map)
		return (free(ori->player), -1);
	init_player(ori);
	if (check_init_p(ori))
		return (1);
	printf("diretion boussole :%f\n", ori->player->dir_angle);
	printf("horizontl%f vertical:%f\n", ori->player->dir_x, ori->player->dir_y);
	printf("posxplayer %f pos_yplayer %f\n", ori->player->pos_x,
		ori->player->pos_y);
	raycasting(ori);
	if (start_mlx(ori))
		return (1);
	return (0);
}
