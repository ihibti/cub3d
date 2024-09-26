#include "cub3d.h"

unsigned int	create_rgb(int t, int r, int g, int b)
{
	return ((t & 0xFF) << 24 | (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF));
}

void	draw_ceiling(t_ori *ori, char *img_data, int x, int *y)
{
	(void)img_data;
	while (*y < ori->player->ray->drawstart && *y < SCREEN_H)
	{
		*((int *)ori->display.data + (*y) * SCREEN_W + x) = create_rgb(0,
				ori->ceiling.r, ori->ceiling.g, ori->ceiling.b);
		(*y)++;
	}
}

void	draw_floor(t_ori *ori, char *img_data, int x, int y)
{
	(void)img_data;
	while (y < SCREEN_H)
		*((int *)ori->display.data + y++ * SCREEN_W + x) = create_rgb(0,
				ori->floor.r, ori->floor.g, ori->floor.b);
}