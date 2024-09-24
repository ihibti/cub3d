/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:27 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/24 17:26:06 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	han_inp_press(int key, t_ori *ori)
{
	if (key == XK_Escape || key == XK_q)
		brexit(ori);
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
		brexit(ori);
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
