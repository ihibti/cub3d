/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_supersaiyan3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:30:25 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/26 13:31:05 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_map_final(t_ori *ori, char **map_final)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ori->map_height)
	{
		j = 0;
		while (j < ori->map_width)
		{
			if (j < (int)ft_strlen(ori->map[i]))
			{
				if ((unsigned char)ori->map[i][j] != ' '
					&& (unsigned char)ori->map[i][j] != '\t')
					map_final[i][j] = ori->map[i][j];
				else
					map_final[i][j] = '1';
			}
			else
				map_final[i][j] = '1';
			j++;
		}
		map_final[i++][j] = '\0';
	}
	map_final[i] = NULL;
}

void	final_map(t_ori *ori)
{
	int		i;
	char	**map_final;

	i = 0;
	map_final = NULL;
	ori->map_width = find_longest_line(ori->map);
	map_final = malloc(sizeof(char *) * (ori->map_height + 1));
	if (!map_final)
		brexit(ori, NULL);
	while (i < ori->map_height)
	{
		map_final[i] = malloc(sizeof(char) * (ori->map_width + 1));
		if (!map_final[i])
			brexit(ori, NULL);
		i++;
	}
	copy_map_final(ori, map_final);
	free_tab(ori->map);
	ori->map = map_final;
}
