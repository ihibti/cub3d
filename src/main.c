/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:30:53 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/23 18:01:46 by gchenot          ###   ########.fr       */
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
	parsing(&ori);
	if (init(&ori))
		brexit(&ori);
	return (0);
}

