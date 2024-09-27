/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/27 13:43:30 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	swap_ms(t_ori *ori)
{
	if (ori->movespeed == 0.08)
	{
		ori->movespeed = 0.01;
		ori->cam_speed = 0.001;
	}
	else
	{
		ori->movespeed = 0.08;
		ori->cam_speed = 0.05;
	}
	ori->mouse = 0;
	return (0);
}

int	han_inp_press(int key, t_ori *ori)
{
	if (key == XK_p)
		swap_ms(ori);
	if (key == XK_Escape || key == XK_q)
		brexit(ori, NULL);
	if (key == XK_w)
		ori->w = true;
	if (key == XK_s)
		ori->s = true;
	if (key == XK_d)
		ori->d = true;
	if (key == XK_a)
		ori->a = true;
	if (key == XK_Left)
		ori->left = true;
	if (key == XK_Right)
		ori->right = true;
	return (0);
}

int	han_inp_release(int key, t_ori *ori)
{
	if (key == XK_Escape || key == XK_q)
		brexit(ori, NULL);
	if (key == XK_w)
		ori->w = false;
	if (key == XK_s)
		ori->s = false;
	if (key == XK_d)
		ori->d = false;
	if (key == XK_a)
		ori->a = false;
	if (key == XK_Left)
		ori->left = false;
	if (key == XK_Right)
		ori->right = false;
	return (0);
}

int	han_mouse_move(int x, int y, void *param)
{
	t_ori	*ori;

	(void)y;
	ori = (t_ori *)param;
	if (x > (SCREEN_W / 2) + (SCREEN_W / 4))
	{
		ori->right = true;
		ori->left = false;
	}
	else if (x < (SCREEN_W / 2) - (SCREEN_W / 4))
	{
		ori->right = false;
		ori->left = true;
	}
	else
	{
		ori->left = false;
		ori->right = false;
	}
	ori->mouse = 1;
	return (0);
}
