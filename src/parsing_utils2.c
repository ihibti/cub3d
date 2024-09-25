/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:38:24 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/25 14:42:39 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_fd(t_ori *ori)
{
	ori->fd = open(ori->file, O_RDONLY);
	if (ori->fd < 0)
	{
		ft_putstr_fd("Error: cannot open file\n", 2);
		exit(0);
	}
}

void	valid_extension(t_ori *ori, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len >= 5 && ft_strcmp(str + len - 4, ".cub") == 0)
	{
		ori->file = ft_strdup(str);
		if (!ori->file)
			// (brexit(ori));
			brexit(ori, ERROR_DUP, NULL);
		return ;
	}
	else
	{
		ft_putstr_fd("Error: your args are trash\n", 2);
		ft_putstr_fd("-> .cub file expected\n", 2);
		exit(EXIT_FAILURE);
	}
}

// TEST FUNCTION
void	printf_map(char **map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k])
				printf("[%c] ", map[i][k]);
			k++;
		}
		printf("\n");
		i++;
	}
}
