/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:41:51 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/24 15:26:35 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char	**allocate_map(void)
// {
// 	char	**map;
// 	char	*data[20];
// 	// int		j;

// 	data[0] = "11111111111111111111";
// 	data[1] = "10000000000000000001";
// 	data[2] = "10100010000000000001";
// 	data[3] = "10111110011110000001";
// 	data[4] = "10100010000000000001";
// 	data[5] = "10000000100000000001";
// 	data[6] = "10000000020000000001";
// 	data[7] = "10000000000000000001";
// 	data[8] = "10000000002000000001";
// 	data[9] = "10000000000000000001";
// 	data[10] = "10000000000200000001";
// 	data[11] = "10000000000000000001";
// 	data[12] = "10000000000000000001";
// 	data[13] = "10000000000000000001";
// 	data[14] = "10000000000000000001";
// 	data[15] = "10000111001100000001";
// 	data[16] = "10000000001000000001";
// 	data[17] = "10000000N00000000001";
// 	data[18] = "10000000000000000001";
// 	data[19] = "11111111111111111111";
// 	map = (char **)malloc(22 * sizeof(char *));
// 	if (map == NULL)
// 	{
// 		perror("Erreur d'allocation de mémoire");
// 		return (NULL);
// 	}
// 	for (int i = 0; i < 20; i++)
// 	{
// 		map[i] = (char *)malloc(21 * sizeof(char));
// 		if (map[i] == NULL)
// 		{
// 			perror("Erreur d'allocation de mémoire");
// 			for (int j = 0; j < i; j++)
// 			{
// 				free(map[j]);
// 			}
// 			free(map);
// 			return (NULL);
// 		}
// 	}
// 	for (int i = 0; i < 20; i++)
// 	{
// 		for (int j = 0; j < 21; j++)
// 		{
// 			map[i][j] = data[i][j];
// 		}
// 		map[i][20] = '\0';
// 	}
// 	map[20] = 0;
// 	// j = 0;
// 	return (map);
// }

int	init_player(t_ori *ori)
{
	// ft_memset(ori->player->ray, 0, sizeof(t_ray));
	ori->player->ray = malloc(sizeof(t_ray));
	if (!ori->player->ray)
		return ((brexit(ori)), 1);
	if (init_pl(ori))
		// return (free(ori->player), 1);
		return ((brexit(ori)), 1);
	init_dirangle(ori);
	ori->a = false;
	ori->w = false;
	ori->s = false;
	ori->d = false;
	ori->left = false;
	ori->right = false;
	ori->player->dir_x = cos(ori->player->dir_angle);
	ori->player->dir_y = sin(ori->player->dir_angle);
	ori->recast = 1;
	ori->img_h = 64;
	ori->img_w = 64;
	return (0);
}

/* static int	init_color(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
	return (0);
} */

int	init(t_ori *ori)
{
	// ft_memset(ori, 0, sizeof(t_ori));
	ori->player = malloc(sizeof(t_player));
	if (!ori->player)
		return ((brexit(ori)), 1);
	// ori->floor = RED;
	// ori->sky = BLUE;
	// ori->wall = BLACK;
	ori->recast = true;
	// ori->file = ft_strdup(file);
	// if (!ori->file)
	// 	return ((brexit(ori)), 1);
	ori->nb_line = -1;
	// open_fd(ori);
	// parsing_map(ori);
	// // opeinit_color(&ori->ceiling,);
	// init_color(&ori->floor);n_fd(ori);
	// create_map(ori);
	//
	if (init_player(ori))
		return (1);
	if (check_init_p(ori))
		return (1);
	if (start_mlx(ori))
		return (1);
	return (0);
}

// int	init(t_ori *ori)
// {
// 	ft_memset(ori, 0, sizeof(t_ori));
// 	ori->player = malloc(sizeof(t_player));
// 	if (ori->player == NULL)
// 		return ((brexit(ori)), 1);
// 	ori->floor = RED;
// 	ori->sky = BLUE;
// 	ori->wall = BLACK;
// 	// ori->fd = -1;
// 	ori->recast = true;
// 	if (!ori->player)
// 		return ((brexit(ori)), -1);
// 	ori->map = allocate_map();
// 	if (!ori->map)
// 		return ((brexit(ori)), -1);
// 	init_player(ori);
// 	if (check_init_p(ori))
// 		return (1);
// 	// if (start_mlx(ori))
// 	// 	return (1);
// 	return (0);
// }
