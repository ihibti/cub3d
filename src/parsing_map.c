/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:52:29 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/26 16:59:27 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_map(t_ori *ori, char *line, int j)
{
	ori->nb_line++;
	if (!*line)
		return ;
	if (!ori->map_start_line)
		ori->map_start_line = j;
}

// int	jump_space(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (ft_isspace(str[i]))
// 		i++;
// 	return (i);
// }
	// line += jump_space(line);

static void	parse_line(t_ori *ori, char *line, int i)
{
	if ((!ft_strncmp(line, "NO ", 3) && ori->n_path) || (!ft_strncmp(line,
				"EA ", 3) && ori->e_path) || (!ft_strncmp(line, "SO ", 3)
			&& ori->s_path) || (!ft_strncmp(line, "WE ", 3) && ori->w_path))
		(ft_putstr_fd(ERROR_PATH, 2), brexit(ori, line));
	else if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "EA ", 3)
		|| !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "WE ", 3))
		parsing_textures(ori, line);
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		parsing_colors(ori, line);
	else if (ori->e_path && ori->n_path && ori->w_path && ori->s_path
		&& ori->parsed_c && ori->parsed_f && line[0] != '\0')
	{
		ori->inside_map = 1;
		parse_map(ori, line, i);
	}
	else if (line[0] == '\0' && !ori->inside_map)
		return ;
	else if (line[0] == '\n' && !ori->inside_map)
		return ;
	else
		(ft_putstr_fd(ERROR_PARSING, 2), brexit(ori, line));
	if (ori->nb_start > 1)
		(ft_putstr_fd(ERROR_START, 2), brexit(ori, line));
}

void	parsing_map(t_ori *ori)
{
	char	*line;
	int		i;
	int		map_line_count;

	i = 0;
	map_line_count = 0;
	ori->map_start_line = 0;
	ori->parsed_c = 0;
	ori->parsed_f = 0;
	while (1)
	{
		line = get_next_line(ori->fd);
		if (!line)
			break ;
		i++;
		parse_line(ori, line, i);
		if (i >= ori->map_start_line)
			map_line_count++;
		free(line);
	}
	if (close(ori->fd))
		(ft_putstr_fd(ERROR_CLOSEFD, 2), brexit(ori, line));
	ori->nb_line = map_line_count;
}

int	check_map_leaks(t_ori *ori, int x, int y)
{
	if (ori->map[y][x] == '0' || contains_char("NSWE", ori->map[y][x]))
	{
		if (x == 0 || x == ori->map_width - 1 || y == 0 || y == ori->map_height
			- 1)
			return (1);
		if (ori->map[y][x + 1] == '\0' || ori->map[y][x - 1] == '\0'
			|| ori->map[y + 1][x] == '\0' || ori->map[y - 1][x] == '\0')
			return (1);
		if (ori->map[y][x + 1] == ' ' || ori->map[y][x - 1] == ' ' || ori->map[y
			+ 1][x] == ' ' || ori->map[y - 1][x] == ' ')
			return (1);
	}
	if (x < ori->map_width - 1 && ori->map[y][x + 1] != '\0')
		return (check_map_leaks(ori, x + 1, y));
	else if (y < ori->map_height - 1 && ori->map[y + 1] != NULL)
		return (check_map_leaks(ori, 0, y + 1));
	return (0);
}
