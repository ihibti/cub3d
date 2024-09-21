/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:38:43 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/20 10:06:57 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//UNUSED FUNCTION
// int	draw_win(t_ori *ori)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (x <= SCREEN_W)
// 	{
// 		while (y <= SCREEN_H)
// 		{
// 			if (y < (SCREEN_H / 2))
// 				mlx_pixel_put(ori->mlxptr, ori->mlxwin, x, y, ori->sky);
// 			else
// 				mlx_pixel_put(ori->mlxptr, ori->mlxwin, x, y, ori->floor);
// 			y++;
// 		}
// 		y = 0;
// 		x++;
// 	}
// 	return (0);
// }

// static void	open_textures2(t_ori *ori)
// {
// 	ori->textures[2].img = mlx_xpm_file_to_image(ori->mlxptr,
// 			"textures/bluestone.xpm", &ori->textures[2].width,
// 			&ori->textures[2].height);
// 	if (!ori->textures[2].img)
// 		brexit(ori);
// 	ori->textures[2].data = mlx_get_data_addr(ori->textures[2].img,
// 			&ori->textures[2].bpp, &ori->textures[2].width,
// 			&ori->textures[2].height);
// 	if (!ori->textures[2].data)
// 		brexit(ori);
// 	ori->textures[3].img = mlx_xpm_file_to_image(ori->mlxptr,
// 			"textures/greystone.xpm", &ori->textures[3].width,
// 			&ori->textures[3].height);
// 	if (!ori->textures[3].img)
// 		brexit(ori);
// 	ori->textures[3].data = mlx_get_data_addr(ori->textures[3].img,
// 			&ori->textures[3].bpp, &ori->textures[3].width,
// 			&ori->textures[3].height);
// 	if (!ori->textures[3].data)
// 		brexit(ori);
// }

// int	open_textures(t_ori *ori)
// {
// 	ori->textures[0].img = mlx_xpm_file_to_image(ori->mlxptr,
// 			"textures/eagle.xpm", &ori->textures[0].width,
// 			&ori->textures[0].height);
// 	if (!ori->textures[0].img)
// 		brexit(ori);
// 	ori->textures[0].data = mlx_get_data_addr(ori->textures[0].img,
// 			&ori->textures[0].bpp, &ori->textures[0].width,
// 			&ori->textures[0].height);
// 	if (!ori->textures[0].data)
// 		brexit(ori);
// 	ori->textures[1].img = mlx_xpm_file_to_image(ori->mlxptr,
// 			"textures/colorstone.xpm", &ori->textures[1].width,
// 			&ori->textures[1].height);
// 	if (!ori->textures[1].img)
// 		brexit(ori);
// 	ori->textures[1].data = mlx_get_data_addr(ori->textures[1].img,
// 			&ori->textures[1].bpp, &ori->textures[1].width,
// 			&ori->textures[1].height);
// 	if (!ori->textures[1].data)
// 		brexit(ori);
// 	open_textures2(ori);
// 	return (0);
// }

void	init_mlx(t_ori *ori)
{
	ori->mlxptr = mlx_init();
	if (!ori->mlxptr)
		// exit_game(ori, ERROR_MLX, NULL);
		brexit(ori);
}

static void	init_mlx_window(t_ori *ori)
{
	ori->mlxwin = mlx_new_window(ori->mlxptr, SCREEN_W, SCREEN_H, "cub3D");
	if (!ori->mlxwin)
		brexit(ori);
	ori->mlx_img = mlx_new_image(ori->mlxptr, SCREEN_W, SCREEN_H);
	if (!ori->mlx_img)
		brexit(ori);
	ori->img_addr = mlx_get_data_addr(ori->mlx_img, &ori->display.bpp,
			&ori->img_slen, &ori->img_endian);
	if (!ori->mlx_img)
		brexit(ori);

	//NOT USING ENDIAN OR SIZELEN (WHICH ONE IS CORRECT?)
	// ori->display.img = mlx_new_image(ori->mlxptr, SCREEN_W, SCREEN_H);
	// if (!ori->display.img)
	// 	// exit_game(ori, ERROR_MLXIMG, NULL);
	// 	brexit(ori);
	// ori->display.data = mlx_get_data_addr(ori->display.img, &ori->display.bpp,
	// 		&ori->display.width, &ori->display.height);
	// if (!ori->display.data)
	// 	// exit_game(ori, ERROR_MLXDATA, NULL);
	// 	brexit(ori);
}

static void	mlx_hooks(t_ori *ori)
{
	mlx_hook(ori->mlxwin, 3, 2L, han_inp_release, ori);
	mlx_hook(ori->mlxwin, 2, 1L, han_inp_press, ori);
	mlx_hook(ori->mlxwin, 17, 1, brexit, ori);
	mlx_loop_hook(ori->mlxptr, raycasting, ori);
	mlx_loop(ori->mlxptr);
}

int	start_mlx(t_ori *ori, char *file)
{
	init_mlx(ori);
	ori->recast = 1;
	ori->file = file;
	ori->nb_line = -1;
	init_mlx_window(ori);
	// if (open_textures(ori))
	// 	return (1);
	mlx_hooks(ori);
	return (0);
}
