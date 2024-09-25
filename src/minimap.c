#include "cub3d.h"

int	unsafe(int x, int y, char **map)
{
	int	i;

	i = 0;
	if (x < 0 || y < 0)
		return (1);
	while (map[i])
		i++;
	if (y >= i)
		return (1);
	if (x >= ft_strlen(map[y]))
		return (1);
	return (0);
}

static int	collision(char **map, t_ori *ori, int stepx, int stepy)
{
	if (stepx == 0 || stepy == 0)
		return (1);
	if (unsafe(ori->player->x_map + stepx, ori->player->y_map + stepy, map))
		return (0);
	if (map[ori->player->y_map + stepy][ori->player->x_map] != '0')
	{
		if (map[ori->player->y_map][ori->player->x_map + stepx] != '0')
			return (0);
	}
	return (1);
}
int	is_pov(int x, int y, t_ori *ori)
{
	int		stepx;
	int		stepy;
	double	angle;

	angle = ori->player->dir_angle;
	if (cos(angle) > 0.5)
		stepx = 1;
	else if (cos(angle) < -0.5)
		stepx = -1;
	else
		stepx = 0;
	if (sin(angle) > 0.5)
		stepy = -1;
	else if (sin(angle) < -0.5)
		stepy = 1;
	else
		stepy = 0;
	if (x != ori->player->x_map + stepx || y != ori->player->y_map + stepy)
		return (0);
	if (ori->map[ori->player->y_map + stepy][ori->player->x_map + stepx] == '0')
		if (collision(ori->map, ori, stepx, stepy))
			return (1);
	return (0);
}

static void	draw_square(int x, int y, u_int32_t color, t_ori *ori)
{
	int	startx;
	int	starty;
	int	endx;
	int	endy;

	startx = (SCREEN_W / 28) * x;
	starty = (SCREEN_H / 28) * y;
	endx = startx + (SCREEN_W / 28);
	endy = starty + (SCREEN_H / 28);
	y = starty;
	while (startx < endx)
	{
		while (y <= endy)
		{
			*((int *)ori->display.data + startx + y * SCREEN_W) = color;
			y++;
		}
		y = starty;
		startx++;
	}
}

void	draw_minimap(t_ori *ori)
{
	char	**map;
	int		x;
	int		y;
	int		i;
	int		j;

	(void)map; // jsp pq jpeux pas compile avec chez wam
	init_mnmap(&i, &j, ori);
	x = 0;
	y = 0;
	map = ori->map;
	while (x < 8)
	{
		while (y < 8)
		{
			draw_square(x, y, get_color_mini(i, j++, ori->map, ori), ori);
			y++;
		}
		i++;
		j -= 8;
		x++;
		y = 0;
	}
}
