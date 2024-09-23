#include "cub3d.h"

void	parsing(t_ori *ori)
{
	open_fd(ori);
    ori->n_path = NULL;
    ori->w_path = NULL;
    ori->e_path = NULL;
    ori->s_path = NULL;    
	parsing_map(ori);
	// open_fd(ori);
	create_map(ori);
	if (check_valid_start(ori->map))
		(ft_putstr_fd("Error with start position\n", 2), brexit(ori));
	if (check_map_leaks(ori, 0, 0))
		(ft_putstr_fd("Error map has a holee\n", 2), brexit(ori));
}