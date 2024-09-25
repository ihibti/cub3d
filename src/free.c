/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:17:26 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/25 12:14:36 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

int	free_map(char **map)
{
	int	i;

	if (map == NULL)
		return (1);
	i = 0;
	while (map[i])
		(free(map[i++]), map[i] = NULL);
	free(map);
	map = NULL;
	return (0);
}

static int	free_ray(t_ray *ray)
{
	if (ray)
		(free(ray), ray = NULL);
	return (0);
}

int	free_player(t_player *player)
{
	if (!player)
		return (1);
	if (player->ray)
		free_ray(player->ray), player->ray = NULL;
	free(player);
	player = NULL;
	return (0);
}

int	free_textures(t_ori *ori)
{
	if (ori->n_path)
	{
		mlx_destroy_image(ori->mlxptr, ori->n_path);
		(free(ori->n_path), ori->n_path = NULL);
	}
	if (ori->s_path)
	{
		mlx_destroy_image(ori->mlxptr, ori->s_path);
		(free(ori->s_path), ori->s_path = NULL);
	}
	if (ori->e_path)
	{
		mlx_destroy_image(ori->mlxptr, ori->e_path);
		(free(ori->e_path), ori->e_path = NULL);
	}
	if (ori->w_path)
	{
		mlx_destroy_image(ori->mlxptr, ori->w_path);
		(free(ori->w_path), ori->w_path = NULL);
	}
	printf("textures free\n");
	return (0);
}

int	brexit(t_ori *ori)
{
	if (!ori)
		return (1);
	if (ori->map)
		(free_map(ori->map), ori->map = NULL, printf("map free\n"));
	if (ori->player)
		(free_player(ori->player), ori->player = NULL, printf("player free\n"));
	free_textures(ori);
	if (ori->display.img)
	{
		mlx_destroy_image(ori->mlxptr, ori->display.img);
		ori->display.img = NULL;
		printf("img free\n");
	}
	if (ori->mlxwin)
		(mlx_destroy_window(ori->mlxptr, ori->mlxwin), ori->mlxwin = NULL, printf("win free\n"));
	if (ori->mlxptr)
	{
		mlx_destroy_display(ori->mlxptr);
		free(ori->mlxptr);
		ori->mlxptr = NULL;
		printf("mlx free\n");
	}
	printf("ca free\n");
	// (void)ori;
	// exit(0);
	return (0);
}

int	endgame(t_ori *ori)
{
	if (ori->n_path)
		mlx_destroy_image(ori->mlxptr, ori->n_path);
	if (ori->s_path)
		mlx_destroy_image(ori->mlxptr, ori->s_path);
	if (ori->e_path)
		mlx_destroy_image(ori->mlxptr, ori->e_path);
	if (ori->w_path)
		mlx_destroy_image(ori->mlxptr, ori->w_path);
	if (ori->map)
		free_tab(ori->map);
	mlx_destroy_image(ori->mlxptr, ori->display.img);
	mlx_destroy_window(ori->mlxptr, ori->mlxwin);
	mlx_destroy_display(ori->mlxptr);
	free(ori->mlxptr);
	exit(0);
}

int	exit_err(int error, char *msg)
{
	if (error)
		ft_putstr_fd(msg, 2);
	return (exit(error), error);
}
