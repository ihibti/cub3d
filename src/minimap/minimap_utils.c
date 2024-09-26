/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:06:10 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/26 17:06:15 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mnmap(int *i, int *j, t_ori *ori)
{
	*i = ori->player->x_map - 3;
	*j = ori->player->y_map - 3;
	if (*i < 0)
		*i = 0;
	if (*j < 0)
		i = 0;
}

uint32_t	get_color_mini(int x, int y, char **map, t_ori *ori)
{
	if (unsafe(x, y, map))
		return (BLACK);
	if (x == ori->player->x_map && ori->player->y_map == y)
		return (RED);
	if (is_pov(x, y, ori))
		return (GREEN);
	if (map[y][x] == '0')
		return (WHITE);
	return (GRAY);
}
