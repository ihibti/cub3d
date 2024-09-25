/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:52:19 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/25 14:35:22 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_ori *ori)
{
	open_fd(ori);
	init_textures_paths(ori);
    ori->map_start_line = INT_MAX;
    ori->nb_start = 0;
	parsing_map(ori);
	if (ori->nb_line == 0)
		// ft_putstr_fd("Error: No map\n", 2), brexit(ori);
		brexit(ori, ERROR_MAP, NULL);
	open_fd(ori);
	create_map(ori);
	if (check_valid_start(ori->map))
		// (ft_putstr_fd("Error with start position\n", 2), brexit(ori));
		brexit(ori, ERROR_START, NULL);
	if (check_map_leaks(ori, 0, 0))
		// (ft_putstr_fd("Error map has a holee\n", 2), brexit(ori));
		brexit(ori, ERROR_MAP_LEAKS, NULL);
	final_map(ori);
	printf_map(ori->map);
}