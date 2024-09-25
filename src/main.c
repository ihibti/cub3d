/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:30:53 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/25 14:31:40 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_ori	ori;

	if (ac != 2)
	{
		brexit(NULL, ERROR_ARGS, NULL);
		return (1);
	}
	valid_extension(&ori, av[1]);
	ori.mlxptr = mlx_init();
	parsing(&ori);
	if (init(&ori))
		// brexit(&ori);
		brexit(&ori, ERROR_INIT, NULL);
	return (0);
}
