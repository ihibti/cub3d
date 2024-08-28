/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:40:01 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/26 14:29:58 by ihibti           ###   ########.fr       */
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
	if (ori->player)
		free(ori->player);
	if (ori->mlxwin)
		mlx_destroy_window(ori->mlxptr, ori->mlxwin);
	if (ori->mlxptr)
	{
		mlx_destroy_display(ori->mlxptr);
		free(ori->mlxptr);
	}
	exit(0);
	return (0);
}