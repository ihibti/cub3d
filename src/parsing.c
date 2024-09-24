#include "cub3d.h"

void	init_textures_paths(t_ori *ori)
{
	ori->n_path = NULL;
	ori->w_path = NULL;
	ori->e_path = NULL;
	ori->s_path = NULL;
    ori->inside_map = 0;
}

void	parsing(t_ori *ori)
{
	open_fd(ori);
	init_textures_paths(ori);
    ori->map_start_line = INT_MAX;
    ori->nb_start = 0;
	parsing_map(ori);
	if (ori->nb_line == 0)
		ft_putstr_fd("Error: No map\n", 2), brexit(ori);
	open_fd(ori);
	create_map(ori);
	// if (check_valid_start(ori->map))
	// 	(ft_putstr_fd("Error with start position\n", 2), brexit(ori));
	// if (check_map_leaks(ori, 0, 0))
	// 	(ft_putstr_fd("Error map has a holee\n", 2), brexit(ori));
}