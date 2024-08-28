/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:30:53 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/28 11:29:56 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_firsttep(float x, float vectorx)
{
	int		exem;
	float	ret;

	exem = (int)x;
	if (vectorx > 0)
		ret = fabs(exem + 1 - x);
	else
		ret = fabs(exem - x);
	return (ret);
}

int	main(int ac, char **av)
{
	t_ori	ori;

	(void)av;
	(void)ac;
	printf("fov : %f\n", FOV);
	if (init(&ori))
		return (printf("error init\n"), 1);
	printf("diretion boussole :%f\n", ori.player->dir_angle);
	printf("horizontl%f vertical:%f\n", ori.player->orientation_x,
		ori.player->orientation_y);
	printf("%f\n", get_firstte(0.4, -1));
	return (0);
}
