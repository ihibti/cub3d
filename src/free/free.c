/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:17:26 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/27 12:14:41 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (player->ray)
	{
		free_ray(player->ray);
		player->ray = NULL;
	}
	free(player);
	player = NULL;
	return (0);
}

int	free_textures(t_ori *ori)
{
	if (ori->textures[0].img)
		mlx_destroy_image(ori->mlxptr, ori->textures[0].img);
	if (ori->textures[1].img)
		mlx_destroy_image(ori->mlxptr, ori->textures[1].img);
	if (ori->textures[2].img)
		mlx_destroy_image(ori->mlxptr, ori->textures[2].img);
	if (ori->textures[3].img)
		mlx_destroy_image(ori->mlxptr, ori->textures[3].img);
	if (ori->e_path)
		free(ori->e_path);
	if (ori->n_path)
		free(ori->n_path);
	if (ori->s_path)
		free(ori->s_path);
	if (ori->w_path)
		free(ori->w_path);
	return (0);
}

void	free_gnl(t_ori *ori, char *line)
{
	char	*lines_to_free;

	if (!line)
		return ;
	lines_to_free = "";
	free(line);
	while (1)
	{
		lines_to_free = get_next_line(ori->fd);
		if (!lines_to_free)
			break ;
		free(lines_to_free);
	}
	close(ori->fd);
}

int	brexit(t_ori *ori, char *line)
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
	if (ori->file)
		free(ori->file);
	if (ori->mlxptr)
	{
		mlx_destroy_display(ori->mlxptr);
		free(ori->mlxptr);
		ori->mlxptr = NULL;
	}
	free_gnl(ori, line);
	exit(0);
	return (0);
}
