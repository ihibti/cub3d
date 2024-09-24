#include "cub3d.h"

void	init_textures_paths(t_ori *ori)
{
	ori->n_path = NULL;
	ori->w_path = NULL;
	ori->e_path = NULL;
	ori->s_path = NULL;
}

void	parsing(t_ori *ori)
{
	open_fd(ori);
	init_textures_paths(ori);
    ori->map_start_line = INT_MAX;
    ori->nb_start = 0;
	parsing_map(ori);
	printf("Map parsed\n");
	// open_fd(ori);
	create_map(ori);
	if (check_valid_start(ori->map))
		(ft_putstr_fd("Error with start position\n", 2), brexit(ori));
	if (check_map_leaks(ori, 0, 0))
		(ft_putstr_fd("Error map has a holee\n", 2), brexit(ori));
}