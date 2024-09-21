#include "cub3d.h"

void	parsing(t_ori *ori)
{
	open_file(ori);
	parsing_map(ori);
	open_file(ori);
	create_map(ori);
	if (check_map_leaks(ori, 0, 0))
		exit_game(ori, "Error map\n", NULL);
	// optimizing_map(ori);
	// get_start_position(ori);
}