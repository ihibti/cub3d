/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:30:53 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/24 10:33:27 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_ori	ori;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./cub3D <map_file>\n", 2);
		return (1);
	}
	valid_extension(&ori, av[1]);
	// check_file(&ori);
    ori.mlxptr = mlx_init();
	parsing(&ori);
	if (init(&ori))
		brexit(&ori);
	return (0);
}

