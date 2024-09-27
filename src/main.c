/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:30:53 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/27 13:42:19 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_ori	ori;

	ft_memset(&ori, 0, sizeof(ori));
	if (ac != 2)
	{
		ft_putstr_fd(ERROR_ARGS, 2);
		return (1);
	}
	valid_extension(&ori, av[1]);
	ori.mlxptr = mlx_init();
	if (!ori.mlxptr)
		return (brexit(&ori, NULL));
	parsing(&ori);
	if (init(&ori))
		brexit(&ori, NULL);
	return (0);
}
