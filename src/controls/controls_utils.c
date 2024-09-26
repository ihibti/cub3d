/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/26 11:47:14 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_left(t_ori *ori)
{
	ori->player->dir_angle += (double)(CAMERA_SPEED / 10);
	if (ori->player->dir_angle > (2 * M_PI))
		ori->player->dir_angle -= 2 * M_PI;
	ori->player->dir_x = cos(ori->player->dir_angle);
	ori->player->dir_y = sin(ori->player->dir_angle);
}

void	look_right(t_ori *ori)
{
	ori->player->dir_angle -= (double)(CAMERA_SPEED / 10);
	if (ori->player->dir_angle < 0)
		ori->player->dir_angle += 2 * M_PI;
	ori->player->dir_x = cos(ori->player->dir_angle);
	ori->player->dir_y = sin(ori->player->dir_angle);
}
