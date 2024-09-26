/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:51:42 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/26 17:59:28 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoirgb(const char *str)
{
	long	i;
	long	somme;

	somme = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i] && ((str[i] <= 13 && str[i] >= 9) || str[i] == ' '))
		i++;
	if (str[i] == '-')
		return (-1);
	while (str[i] <= '9' && str[i] >= '0')
	{
		somme = (somme * 10) + (str[i++] - '0');
		if (somme > 255)
			return (-1);
	}
	if (somme == 0)
		return (0);
	return (somme);
}

static char	**valid_color(char *line)
{
	int		i;
	int		j;
	int		k;
	char	**rgb;

	i = 0;
	rgb = ft_split(line, ',');
	if (!rgb)
		return (NULL);
	k = -1;
	while (rgb[++k])
		rgb[k] = ft_strtrimbis(rgb[k], " \n\t");
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
		(ft_putstr_fd(ERROR_CEILINGDUP, 2), brexit(ori, line));
	if (check_comma(line + 2))
		(ft_putstr_fd(ERROR_RGB, 2), brexit(ori, line));
	rgb = valid_color(line + 2);
	if (!rgb)
		(ft_putstr_fd(ERROR_RGB, 2), brexit(ori, line));
	ori->ceiling.r = ft_atoirgb(rgb[0]);
	ori->ceiling.g = ft_atoirgb(rgb[1]);
	ori->ceiling.b = ft_atoirgb(rgb[2]);
	free_tab(rgb);
	if (ori->ceiling.r > 255 || ori->ceiling.g > 255 || ori->ceiling.b > 255
		|| ori->ceiling.r < 0 || ori->ceiling.g < 0 || ori->ceiling.b < 0)
		(ft_putstr_fd(ERROR_RGB, 2), brexit(ori, line));
	ori->parsed_c = 1;
}

static void	parse_color_floor(t_ori *ori, char *line)
{
	char	**rgb;

	if (ori->parsed_f)
		(ft_putstr_fd(ERROR_FLOORDUP, 2), brexit(ori, line));
	if (check_comma(line + 2))
		(ft_putstr_fd(ERROR_RGB, 2), brexit(ori, line));
	rgb = valid_color(line + 2);
	if (!rgb)
		(ft_putstr_fd(ERROR_RGB, 2), brexit(ori, line));
	ori->floor.r = ft_atoirgb(rgb[0]);
	ori->floor.g = ft_atoirgb(rgb[1]);
	ori->floor.b = ft_atoirgb(rgb[2]);
	free_tab(rgb);
	if (ori->floor.r > 255 || ori->floor.g > 255 || ori->floor.b > 255
		|| ori->floor.r < 0 || ori->floor.g < 0 || ori->floor.b < 0)
		(ft_putstr_fd(ERROR_RGB, 2), brexit(ori, line));
	ori->parsed_f = 1;
}

void	parsing_colors(t_ori *ori, char *line)
{
	if (!ft_strncmp(line, "F ", 2))
		parse_color_floor(ori, line);
	else if (!ft_strncmp(line, "C ", 2))
		parse_color_ceiling(ori, line);
}
