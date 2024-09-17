/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:40:01 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/17 20:27:34 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_dimensions(int *x_max, int *y_max, char **map)
{
	int	i;
	int	j;

	if (!map)
		return ;
	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[0][j])
		j++;
	if (x_max)
		*x_max = j;
	if (y_max)
		*y_max = i;
}

int	brexit(t_ori *ori)
{
	if (ori->map)
		free_map(ori->map);
	if (ori->player->ray)
		free(ori->player->ray);
	if (ori->player)
		free(ori->player);
	mlx_destroy_image(ori->mlxptr, ori->textures[0].img);
	mlx_destroy_image(ori->mlxptr, ori->textures[1].img);
	mlx_destroy_image(ori->mlxptr, ori->display.img);
	if (ori->mlxwin)
		mlx_destroy_window(ori->mlxptr, ori->mlxwin);
	if (ori->mlxptr)
	{
		// mlx_destroy_display(ori->mlxptr);
		free(ori->mlxptr);
	}
	exit(0);
	return (0);
}

void	debugging(t_ori *ori)
{
	t_player	*player;
	t_ray		*ray;

	player = ori->player;
	ray = player->ray;
	int x, y;
	x = 0;
	y = 0;
	printf("map:\n");
	while (ori->map[y])
	{
		while (ori->map[y][x])
		{
			if (y == player->y_map && x == player->x_map)
				printf("P");
			else
				printf("%c", ori->map[y][x]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
	printf("playerx %.10f playery %.10f\n", player->pos_x, player->pos_y);
	printf("playerdirx %.10f playerdiry %.10f\n", player->dir_x, player->dir_y);
}
