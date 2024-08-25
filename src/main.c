/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:30:53 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/25 12:30:27 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_ori	ori;

	(void)av;
	(void)ac;
	printf("fov : %f\n", FOV);
	if (init(&ori))
		return (printf("error init\n"), 1);
	printf("%f\n", ori.player->dir_angle);
	printf("x:%f y:%f\n", ori.player->orientation_x, ori.player->orientation_y);
	return (0);
}
