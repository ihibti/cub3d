/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:50:50 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/26 11:38:57 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_textures_no(t_ori *ori)
{

	if (ori->n_path)
	{
		printf("DEBUG testeee\n");
		ori->textures[0].img = mlx_xpm_file_to_image(ori->mlxptr, ori->n_path,
				&ori->textures[0].width, &ori->textures[0].height);
		printf("DEBUG testeee12\n");
		if (!ori->textures[0].img)
			(printf("PASSED\n"), brexit(ori));
		printf("DEBUG testeee13\n");
		ori->textures[0].data = mlx_get_data_addr(ori->textures[0].img,
				&ori->textures[0].bpp, &ori->textures[0].sizeline,
				&ori->textures->endian);
		printf("DEBUG testeee14\n");
		if (!ori->textures[0].data)
			brexit(ori);
		printf("DEBUG testeee15\n");
	}
	else
	{
		ft_putstr_fd("Error: North texture path is missing\n", 2);
		brexit(ori);
	}
	return (0);
}

int	open_textures_so(t_ori *ori)
{

	if (ori->s_path)
	{
		ori->textures[1].img = mlx_xpm_file_to_image(ori->mlxptr, ori->s_path,
				&ori->textures[1].width, &ori->textures[1].height);
		if (!ori->textures[1].img)
			brexit(ori);
		ori->textures[1].data = mlx_get_data_addr(ori->textures[1].img,
				&ori->textures[1].bpp, &ori->textures[1].sizeline,
				&ori->textures->endian);
		if (!ori->textures[1].data)
			brexit(ori);
	}
	else
	{
		ft_putstr_fd("Error: South texture path is missing\n", 2);
		brexit(ori);
	}
	return (0);
}

int	open_textures_ea(t_ori *ori)
{

	if (ori->e_path)
	{
		ori->textures[2].img = mlx_xpm_file_to_image(ori->mlxptr, ori->e_path,
				&ori->textures[2].width, &ori->textures[2].height);
		if (!ori->textures[2].img)
			brexit(ori);
		ori->textures[2].data = mlx_get_data_addr(ori->textures[2].img,
				&ori->textures[2].bpp, &ori->textures[2].sizeline,
				&ori->textures->endian);
		if (!ori->textures[2].data)
			brexit(ori);
	}
	else
	{
		ft_putstr_fd("Error: East texture path is missing\n", 2);
		brexit(ori);
	}
	return (0);
}

int	open_textures_we(t_ori *ori)
{

	if (ori->w_path)
	{
		ori->textures[3].img = mlx_xpm_file_to_image(ori->mlxptr, ori->w_path,
				&ori->textures[3].width, &ori->textures[3].height);
		if (!ori->textures[3].img)
			brexit(ori);
		ori->textures[3].data = mlx_get_data_addr(ori->textures[3].img,
				&ori->textures[3].bpp, &ori->textures[3].sizeline,
				&ori->textures->endian);
		if (!ori->textures[3].data)
			brexit(ori);
	}
	else
	{
		ft_putstr_fd("Error: West texture path is missing\n", 2);
		brexit(ori);
	}
	return (0);
}
