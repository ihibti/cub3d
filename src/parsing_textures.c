/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:16:11 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/26 17:18:21 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*extract_texture_path(t_ori *ori, char *line)
{
	char	*path;

	path = ft_strchr(line, '.');
	if (!path || *(path + 1) == '\0')
	{
		ft_putstr_fd("Error texture path\n", 2);
		brexit(ori, line);
	}
	cut_xpm(path);
	return (path);
}

void	parsing_textures(t_ori *ori, char *line)
{
	char	*path;

	path = extract_texture_path(ori, line);
	if (!ft_strncmp(line, "NO ", 3))
	{
		ori->n_path = ft_strdup(path);
		open_textures_no(ori, line);
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		ori->s_path = ft_strdup(path);
		open_textures_so(ori, line);
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		ori->e_path = ft_strdup(path);
		open_textures_ea(ori, line);
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		ori->w_path = ft_strdup(path);
		open_textures_we(ori, line);
	}
	else
		(ft_putstr_fd("Error unknown texture\n", 2), brexit(ori, line));
}
