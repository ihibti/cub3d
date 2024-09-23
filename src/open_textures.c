#include "cub3d.h"

int	open_textures_no(t_ori *ori)
{
	if (ori->n_path)
	{
		ori->textures[0].img = mlx_xpm_file_to_image(ori->mlxptr, ori->n_path,
				&ori->textures[0].width, &ori->textures[0].height);
		if (!ori->textures[0].img)
			brexit(ori);
		ori->textures[0].data = mlx_get_data_addr(ori->textures[0].img,
				&ori->textures[0].bpp, &ori->textures[0].width,
				&ori->textures[0].height);
		if (!ori->textures[0].data)
			brexit(ori);
	}
	else
	{
		ft_putstr_fd("Error: North texture path is missing\n", 2);
		brexit(ori);
	}
	free(ori->n_path);
	ori->n_path = NULL;
	return (0);
}

int	open_textures_so(t_ori *ori)
{
	if (ori->s_path)
	{
		ori->textures[1].img = mlx_xpm_file_to_image(ori->mlxptr, ori->s_path,
				&ori->textures[0].width, &ori->textures[0].height);
		if (!ori->textures[0].img)
			brexit(ori);
		ori->textures[1].data = mlx_get_data_addr(ori->textures[0].img,
				&ori->textures[0].bpp, &ori->textures[0].width,
				&ori->textures[0].height);
		if (!ori->textures[0].data)
			brexit(ori);
	}
	else
	{
		ft_putstr_fd("Error: South texture path is missing\n", 2);
		brexit(ori);
	}
	free(ori->s_path);
	ori->s_path = NULL;
	return (0);
}

int	open_textures_ea(t_ori *ori)
{
	if (ori->e_path)
	{
		ori->textures[2].img = mlx_xpm_file_to_image(ori->mlxptr, ori->e_path,
				&ori->textures[0].width, &ori->textures[0].height);
		if (!ori->textures[0].img)
			brexit(ori);
		ori->textures[2].data = mlx_get_data_addr(ori->textures[0].img,
				&ori->textures[0].bpp, &ori->textures[0].width,
				&ori->textures[0].height);
		if (!ori->textures[0].data)
			brexit(ori);
	}
	else
	{
		ft_putstr_fd("Error: East texture path is missing\n", 2);
		brexit(ori);
	}
    free(ori->e_path);
	ori->e_path = NULL;
	return (0);
}

int	open_textures_we(t_ori *ori)
{
	if (ori->w_path)
	{
		ori->textures[3].img = mlx_xpm_file_to_image(ori->mlxptr, ori->w_path,
				&ori->textures[0].width, &ori->textures[0].height);
		if (!ori->textures[0].img)
			brexit(ori);
		ori->textures[3].data = mlx_get_data_addr(ori->textures[0].img,
				&ori->textures[0].bpp, &ori->textures[0].width,
				&ori->textures[0].height);
		if (!ori->textures[0].data)
			brexit(ori);
	}
	else
	{
		ft_putstr_fd("Error: West texture path is missing\n", 2);
		brexit(ori);
	}
    free(ori->w_path);
	ori->w_path = NULL;
	return (0);
}
