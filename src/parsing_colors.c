#include "cub3d.h"

static char	**valid_color(char *line)
{
	int		i;
	int		j;
	char	**rgb;

	i = 0;
	rgb = ft_split(line, ',');
	if (!rgb)
		return (NULL);
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				return (free_tab(rgb), (NULL));
			j++;
		}
		i++;
	}
	return (rgb);
}

static void	parse_color_ceiling(t_ori *ori, char *line)
{
	char	**rgb;

	if (check_comma(line + 2))
		exit_game(ori, "RGB impossible [0, 255]\n", line);
	rgb = valid_color(line + 2);
	if (!rgb)
		exit_game(ori, "RGB impossible [0, 255]\n", line);
	ori->ceiling.r = ft_atoi(rgb[0]);
	ori->ceiling.g = ft_atoi(rgb[1]);
	ori->ceiling.b = ft_atoi(rgb[2]);
	free_tab(rgb);
	if (ori->ceiling.r > 255 || ori->ceiling.g > 255 || ori->ceiling.b > 255
		|| ori->ceiling.r < 0 || ori->ceiling.g < 0 || ori->ceiling.b < 0)
	{
		exit_game(ori, "RGB impossible [0, 255]\n", line);
	}
	ori->parsed += 0.5;
}
static void	parse_color_floor(t_ori *ori, char *line)
{
	char	**rgb;

	if (check_comma(line + 2))
		exit_game(ori, "RGB impossible [0, 255]\n", line);
	rgb = valid_color(line + 2);
	if (!rgb)
		exit_game(ori, "RGB impossible [0, 255]\n", NULL);
	ori->floor.r = ft_atoi(rgb[0]);
	ori->floor.g = ft_atoi(rgb[1]);
	ori->floor.b = ft_atoi(rgb[2]);
	free_tab(rgb);
	if (ori->floor.r > 255 || ori->floor.g > 255 || ori->floor.b > 255
		|| ori->floor.r < 0 || ori->floor.g < 0 || ori->floor.b < 0)
	{
		exit_game(ori, "RGB impossible [0, 255]\n", line);
	}
	ori->parsed += 0.5;
}

void	parsing_colors(t_ori *ori, char *line)
{
	if (!ft_strncmp(line, "F ", 2))
		parse_color_floor(ori, line);
	else if (!ft_strncmp(line, "C ", 2))
		parse_color_ceiling(ori, line);
}

// void	parsing_textures(t_ori *ori, char *line)
// {
// 	char	*path;

// 	path = ft_strchr(line, '.');
// 	if (!path)
// 		return ;
// 	else if (!ft_strncmp(line, "NO ", 3))
// 		ori->n_path = mlx_xpm_file_to_image(ori->mlxptr, path, &ori->img_w,
// 				&ori->img_h);
// 	else if (!ft_strncmp(line, "EA ", 3))
// 		ori->e_path = mlx_xpm_file_to_image(ori->mlxptr, path, &ori->img_w,
// 				&ori->img_h);
// 	else if (!ft_strncmp(line, "SO ", 3))
// 		ori->s_path = mlx_xpm_file_to_image(ori->mlxptr, path, &ori->img_w,
// 				&ori->img_h);
// 	else if (!ft_strncmp(line, "WE ", 3))
// 		ori->o_path = mlx_xpm_file_to_image(ori->mlxptr, path, &ori->img_w,
// 				&ori->img_h);
// }

void	parsing_textures(t_ori *ori, char *line)
{
	char	*path;

	path = ft_strchr(line, '.');
	if (!path || *(path + 1) == '\0')
		exit_game(ori, "Invalid texture path\n", line);
	if (!ft_strncmp(line, "NO ", 3))
	{
		ori->n_path = mlx_xpm_file_to_image(ori->mlxptr, path, &ori->img_w,
				&ori->img_h);
		if (!ori->n_path)
			exit_game(ori, ERROR_XPM, line);
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		ori->e_path = mlx_xpm_file_to_image(ori->mlxptr, path, &ori->img_w,
				&ori->img_h);
		if (!ori->e_path)
			exit_game(ori, ERROR_XPM, line);
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		ori->s_path = mlx_xpm_file_to_image(ori->mlxptr, path, &ori->img_w,
				&ori->img_h);
		if (!ori->s_path)
			exit_game(ori, ERROR_XPM, line);
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		ori->o_path = mlx_xpm_file_to_image(ori->mlxptr, path, &ori->img_w,
				&ori->img_h);
		if (!ori->o_path)
			exit_game(ori, ERROR_XPM, line);
	}
	else
	{
		exit_game(ori, "Unknown texture identifier\n", line);
	}
}
