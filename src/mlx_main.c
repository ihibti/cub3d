/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:38:43 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/25 14:44:58 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_start(t_ori *ori)
{
	ori->mlxptr = mlx_init();
	if (!ori->mlxptr)
		return (1);
	ori->mlxwin = mlx_new_window(ori->mlxptr, 640, 360, "cub3d");
	if (!ori->mlxwin)
		return (free(ori->mlxptr), 1);
    
}