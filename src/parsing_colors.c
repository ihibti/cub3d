/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:51:42 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/26 11:37:24 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	for (int k = 0; rgb[k]; k++)
	{
		rgb[k] = ft_strtrimbis(rgb[k], " \n\t");
	}
	while (rgb[i] && *rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (rgb[i][j] && !ft_isdigit(rgb[i][j]))
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

	if (ori->parsed_c)
		(ft_putstr_fd("2 definitions of ceiling", 2), brexit(ori));
	if (check_comma(line + 2))
		(ft_putstr_fd("RGB impossible [0, 255]", 2), brexit(ori));
	rgb = valid_color(line + 2);
	if (!rgb)
		(ft_putstr_fd("RGB impossible [0, 255]", 2), brexit(ori));
	ori->ceiling.r = ft_atoi(rgb[0]);
	ori->ceiling.g = ft_atoi(rgb[1]);
	ori->ceiling.b = ft_atoi(rgb[2]);
	free_tab(rgb);
	if (ori->ceiling.r > 255 || ori->ceiling.g > 255 || ori->ceiling.b > 255
		|| ori->ceiling.r < 0 || ori->ceiling.g < 0 || ori->ceiling.b < 0)
		(ft_putstr_fd("RGB impossible [0, 255]", 2), brexit(ori));
	ori->parsed_c = 1;
}
static void	parse_color_floor(t_ori *ori, char *line)
{
	char	**rgb;

	if (ori->parsed_f)
		(ft_putstr_fd("2 definitions of floor", 2), brexit(ori));
	if (check_comma(line + 2))
		(ft_putstr_fd("RGB impossible [0, 255]", 2), brexit(ori));
	rgb = valid_color(line + 2);
	if (!rgb)
		(ft_putstr_fd("RGB impossible [0, 255]", 2), brexit(ori));
	ori->floor.r = ft_atoi(rgb[0]);
	ori->floor.g = ft_atoi(rgb[1]);
	ori->floor.b = ft_atoi(rgb[2]);
	free_tab(rgb);
	if (ori->floor.r > 255 || ori->floor.g > 255 || ori->floor.b > 255
		|| ori->floor.r < 0 || ori->floor.g < 0 || ori->floor.b < 0)
		(ft_putstr_fd("RGB impossible [0, 255]", 2), brexit(ori));
	ori->parsed_f = 1;
}

void	parsing_colors(t_ori *ori, char *line)
{
	if (!ft_strncmp(line, "F ", 2))
		parse_color_floor(ori, line);
	else if (!ft_strncmp(line, "C ", 2))
		parse_color_ceiling(ori, line);
}

void	parsing_textures(t_ori *ori, char *line)
{
	char	*path;

	path = ft_strchr(line, '.');
	if (!path || *(path + 1) == '\0')
		(ft_putstr_fd("Error texture path\n", 2), brexit(ori));
	cut_xpm(path);
	if (!ft_strncmp(line, "NO ", 3))
	{
		printf("DEBUG test1\n");
		ori->n_path = ft_strdup(path);
		printf("DEBUG test12\n");
		open_textures_no(ori);
		printf("DEBUG test13\n");
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		printf("DEBUG test2\n");
		ori->s_path = ft_strdup(path);
		open_textures_so(ori);
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		printf("DEBUG test3\n");
		ori->e_path = ft_strdup(path);
		open_textures_ea(ori);
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		printf("DEBUG test4\n");
		ori->w_path = ft_strdup(path);
		open_textures_we(ori);
	}
	else
		(ft_putstr_fd("Error unknown texture\n", 2), brexit(ori));
}
