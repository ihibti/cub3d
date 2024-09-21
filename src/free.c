/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:17:26 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/20 15:32:14 by gchenot          ###   ########.fr       */
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
	if (ori->n_path)
		mlx_destroy_image(ori->mlxptr, ori->n_path);
	if (ori->s_path)
		mlx_destroy_image(ori->mlxptr, ori->s_path);
	if (ori->o_path)
		mlx_destroy_image(ori->mlxptr, ori->o_path);
	if (ori->e_path)
		mlx_destroy_image(ori->mlxptr, ori->e_path);
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
	if (ori->mlxptr)
	{
		mlx_destroy_display(ori->mlxptr);
		free(ori->mlxptr);
		ori->mlxptr = NULL;
	}
	exit(0);
	return (0);
}

// static void	empty_gnl(t_ori *ori, char *line)
// {
// 	char	*empty;

// 	empty = "";
// 	free(line);
// 	while (1)
// 	{
// 		empty = get_next_line(ori->fd);
// 		if (!empty)
// 			break ;
// 		free(empty);
// 	}
// }

// void	brexit(t_ori *ori, char *error, char *line)
// {
// 	if (error)
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		ft_putstr_fd(error, 2);
// 	}
// 	// if (line)
// 	// 	empty_gnl(ori, line);
// 	if (ori)
// 		free_game(ori);
// 	if (error)
// 		exit(1);
// 	exit(0);
// }

int exit_err(int error, char *msg)
{
	if (error)
		ft_putstr_fd(msg, 2);
	return(exit(error), error);
}