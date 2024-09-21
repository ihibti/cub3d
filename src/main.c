/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:30:53 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/17 20:49:56 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	valid_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len >= 5 && ft_strcmp(str + len - 4, ".cub") == 0)
		return ;
	else
	{
		ft_putstr_fd("Error\nInvalid arg\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_ori	ori;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./cub3D <map_file>\n", 2);
		return (1);
	}
	valid_extension(av[1]);
	if (init(&ori, av[1])) // Pass the file name to init
		brexit(&ori);
	// start_mlx(&ori, av[1]);
	return (0);
}

