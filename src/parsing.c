#include "cub3d.h"

void	parsing(t_ori *ori)
{
	open_file(ori);
	parsing_map(ori);
	open_file(ori);
	create_map(ori);
	if (check_valid_start(ori->map))
		(ft_putstr_fd("Error with start position\n", 2), brexit(ori));
	if (check_map_leaks(ori, 0, 0))
		(ft_putstr_fd("Error map has a holee\n", 2), brexit(ori));
}