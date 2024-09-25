/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:41:51 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/25 14:32:49 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_var(t_ori *ori)
{
	if (!ori || !ori->player)
		return (1);
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
	ori->nb_line = -1;
	return (0);
}

static int	init_player(t_ori *ori)
{
	if (!ori)
		return (1);
	ori->player->ray = malloc(sizeof(t_ray));
	if (!ori->player->ray)
		return ((brexit(ori, ERROR_INITR, NULL)), 1);
	if (init_pl(ori))
		return ((brexit(ori, ERROR_INIT, NULL)), 1);
	init_dirangle(ori);
	init_var(ori);
	return (0);
}

void	init_textures_paths(t_ori *ori)
{
	if (!ori)
		return ;
	ori->n_path = NULL;
	ori->w_path = NULL;
	ori->e_path = NULL;
	ori->s_path = NULL;
	ori->inside_map = 0;
}

int	init(t_ori *ori)
{
	if (!ori)
		return (1);
	ori->player = malloc(sizeof(t_player));
	if (!ori->player)
		// return ((brexit(ori)), 1);
		return (brexit(ori, ERROR_MALLOC, NULL), 1);
	ori->recast = true;
	if (init_player(ori))
		// return ((brexit(ori)), 1);
		return (brexit(ori, ERROR_INITP, NULL), 1);
	if (check_init_p(ori))
		// return ((brexit(ori)), 1);
		return (brexit(ori, ERROR_INITP, NULL), 1);
	if (start_mlx(ori))
		// return ((brexit(ori)), 1);
		return (brexit(ori, ERROR_INIT, NULL), 1);
	return (0);
}
