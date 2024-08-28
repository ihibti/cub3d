/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:30:53 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/28 14:26:47 by ihibti           ###   ########.fr       */
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
	printf("diretion boussole :%f\n", ori.player->dir_angle);
	printf("horizontl%f vertical:%f\n", ori.player->dir_x, ori.player->dir_y);
	return (0);
}
