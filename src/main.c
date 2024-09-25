/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:30:53 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/25 16:34:24 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_ori	ori;

	memset(&ori, 0, sizeof(ori));
	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./cub3D <map_file>\n", 2);
		return (1);
	}
	valid_extension(&ori, av[1]);
	ori.mlxptr = mlx_init();
	if (!ori.mlxptr)
		return (brexit(&ori));
	parsing(&ori);
	if (init(&ori))
		brexit(&ori);
	return (0);
}
