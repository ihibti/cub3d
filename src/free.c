/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:17:26 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/26 13:51:26 by gchenot          ###   ########.fr       */
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

	lines_to_free = "";
	free(line);
	while (1)
	{
		lines_to_free = get_next_line(ori->fd);
		if (!lines_to_free)
			break ;
		free(lines_to_free);
	}
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
	mlx_destroy_display(ori->mlxptr);
	free(ori->mlxptr);
	ori->mlxptr = NULL;
	// (void)ori;
	free_gnl(ori, line);
	exit(0);
	return (0);
}

int	endgame(t_ori *ori)
{
	free_textures(ori);
	if (ori->map)
		free_tab(ori->map);
	// mlx_destroy_image(ori->mlxptr, ori->display.img);
	// mlx_destroy_window(ori->mlxptr, ori->mlxwin);
	// mlx_destroy_display(ori->mlxptr);
	// free(ori->mlxptr);
	if (ori->display.img)
	{
		mlx_destroy_image(ori->mlxptr, ori->display.img);
		ori->display.img = NULL;
		printf("img free\n");
	}
	if (ori->mlxwin)
		(mlx_destroy_window(ori->mlxptr, ori->mlxwin), ori->mlxwin = NULL,
			printf("win free\n"));
	if (ori->mlxptr)
	{
		mlx_destroy_display(ori->mlxptr);
		free(ori->mlxptr);
		ori->mlxptr = NULL;
		printf("mlx free\n");
	}
	// mlx_destroy_display(ori->mlxptr);
	// free(ori->mlxptr);
	exit(0);
}
