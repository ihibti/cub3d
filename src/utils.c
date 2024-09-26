/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:40:01 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/26 12:44:16 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_dimensions(int *x_max, int *y_max, char **map)
{
	int	i;
	int	j;

	if (!map)
		return ;
	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[0][j])
		j++;
	if (x_max)
		*x_max = j;
	if (y_max)
		*y_max = i;
}

void	cut_xpm(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		{
			str[i] = 0;
			return ;
		}
		i++;
	}
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}
