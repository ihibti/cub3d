/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:17:26 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/25 17:18:57 by ihibti           ###   ########.fr       */
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
		i++;
	}
	free(tab);
}

int	free_map(char **map)
{
	int	i;

	if (map == NULL)
		return (1);
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (0);
}

static int	free_ray(t_ray *ray)
{
	if (ray)
		free(ray);
	return (0);
}

int	free_player(t_player *player)
{
	if (!player)
		return (1);
	free_ray(player->ray);
	free(player);
	return (0);
}

int	free_textures(t_ori *ori)
{
	mlx_destroy_image(ori->mlxptr, ori->textures[0].img);
	mlx_destroy_image(ori->mlxptr, ori->textures[1].img);
	mlx_destroy_image(ori->mlxptr, ori->textures[2].img);
	mlx_destroy_image(ori->mlxptr, ori->textures[3].img);
	free(ori->e_path);
	free(ori->n_path);
	free(ori->s_path);
	free(ori->w_path);
	return (0);
}

int	brexit(t_ori *ori)
{
	if (ori->map)
		(free_map(ori->map), ori->map = NULL);
	if (ori->player)
		(free_player(ori->player), ori->player = NULL);
	free_textures(ori);
	if (ori->display.img)
	{
		mlx_destroy_image(ori->mlxptr, ori->display.img);
		ori->display.img = NULL;
	}
	if (ori->mlxwin)
		(mlx_destroy_window(ori->mlxptr, ori->mlxwin), ori->mlxwin = NULL);
	mlx_destroy_display(ori->mlxptr);
    if (ori->file)
        free(ori->file);
	free(ori->mlxptr);
	ori->mlxptr = NULL;
    exit(0);
	return (0);
}

int	exit_err(int error, char *msg)
{
	if (error)
		ft_putstr_fd(msg, 2);
	return (exit(error), error);
}
