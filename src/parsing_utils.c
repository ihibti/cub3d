/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:40:02 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/26 16:49:53 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_valid_start(char **map)
{
	int	i;
	int	j;
	int	start;

	start = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				start++;
			j++;
		}
		i++;
	}
	if (start > 1 || start == 0)
		return (1);
	return (0);
}

int	check_comma(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	// i = jump_space(line);
	if (!line[i])
		return (1);
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma == 2)
		return (0);
	return (1);
}

int	contains_char(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
