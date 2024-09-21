#include "cub3d.h"

static void	parse_map(t_ori *ori, char *line, int j)
{
	int	i;

	i = 0;
	ori->nb_line++;
	if (!*line)
		return ;
	if (!ori->map_start_line)
		ori->map_start_line = j;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
			ori->nb_start++;
		else if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ')
			exit_game(ori, "Impossible value\n", line);
		i++;
	}
}

static void	parse_line(t_ori *ori, char *line, int i)
{
	if ((!ft_strncmp(line, "NO ", 3) && ori->n_path) || (!ft_strncmp(line,
				"EA ", 3) && ori->e_path) || (!ft_strncmp(line, "SO ", 3)
			&& ori->s_path) || (!ft_strncmp(line, "WE ", 3) && ori->o_path))
		exit_game(ori, "Path already registered\n", line);
	else if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "EA ", 3)
		|| !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "WE ", 3))
		parsing_textures(ori, line);
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		parsing_colors(ori, line);
	else if (ori->e_path && ori->n_path && ori->o_path && ori->s_path
		&& ori->parsed == 1 && line[0] != '\0')
	{
		ori->inside_map = 1;
		parse_map(ori, line, i);
	}
	else if (line[0] == '\0' && !ori->inside_map)
		return ;
	else
		exit_game(ori, "Error parsing\n", line);
	if (ori->nb_start > 1)
		exit_game(ori, "Too much starting position\n", line);
}

void	parsing_map(t_ori *ori)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(ori->fd);
		i++;
		if (!line)
			break ;
		parse_line(ori, line, i);
		free(line);
	}
	if (close(ori->fd) < 0)
		exit_game(ori, "Impossible to close FD\n", line);
}

int	check_valid_start(char **map)
{
	int	i;
	int	j;
	int	start;

	start = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				start++;
			j++;
		}
		i++;
	}
	if (start > 1 || start == 0)
		return (1);
	return (0);
}

static int	contains_char(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}


int	check_map_leaks(t_ori *ori, int x, int y)
{
	if (ori->map[y][x] == '0' || contains_char("NSWE", ori->map[y][x]))
	{
		if (x == 0 || x == ori->map_width - 1 || y == 0
			|| y == ori->map_height - 1)
			return (1);
		if (ori->map[y][x + 1] == '\0' || ori->map[y][x - 1] == '\0'
			|| ori->map[y + 1][x] == '\0' || ori->map[y - 1][x] == '\0')
			return (1);
		if (ori->map[y][x + 1] == ' ' || ori->map[y][x - 1] == ' '
			|| ori->map[y + 1][x] == ' ' || ori->map[y - 1][x] == ' ')
			return (1);
	}
	if (x < ori->map_width - 1 && ori->map[y][x + 1] != '\0')
		return (check_map_leaks(ori, x + 1, y));
	else if (y < ori->map_height - 1 && ori->map[y + 1] != NULL)
		return (check_map_leaks(ori, 0, y + 1));
	return (0);
}