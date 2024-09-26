/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:52:19 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/26 11:31:18 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_ori *ori)
{
	printf("DEBUG 1\n");
	open_fd(ori);
	printf("DEBUG 2\n");
	init_textures_paths(ori);
    ori->map_start_line = INT_MAX;
    ori->nb_start = 0;
	printf("DEBUG 3\n");
	parsing_map(ori);
	if (ori->nb_line == 0)
		ft_putstr_fd("Error: No map\n", 2), brexit(ori);
	printf("DEBUG 4\n");
	open_fd(ori);
	printf("DEBUG 5\n");
	create_map(ori);
	printf("DEBUG 6\n");
	if (check_valid_start(ori->map))
		(ft_putstr_fd("Error with start position\n", 2), brexit(ori));
	printf("DEBUG 7\n");
	if (check_map_leaks(ori, 0, 0))
		(ft_putstr_fd("Error map has a holee\n", 2), brexit(ori));
	printf("DEBUG 8\n");
	final_map(ori);
	printf("DEBUG 9\n");
	printf_map(ori->map);
	printf("DEBUG 10\n");
}