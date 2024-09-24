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
}

int	jump_space(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

static void	parse_line(t_ori *ori, char *line, int i)
{
    line += jump_space(line);
	if ((!ft_strncmp(line, "NO ", 3) && ori->n_path) || (!ft_strncmp(line,
				"EA ", 3) && ori->e_path) || (!ft_strncmp(line, "SO ", 3)
			&& ori->s_path) || (!ft_strncmp(line, "WE ", 3) && ori->w_path))
		(ft_putstr_fd("Error Path already registered\n", 2), brexit(ori));
	else if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "EA ", 3)
		|| !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "WE ", 3))
		parsing_textures(ori, line);
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		parsing_colors(ori, line);
	else if (ori->e_path && ori->n_path && ori->w_path && ori->s_path
		&& ori->parsed_c && ori->parsed_f && line[0] != '\0')
	{
		ori->inside_map = 1;
		parse_map(ori, line, i);
	}
	else if (line[0] == '\0' && !ori->inside_map)
		return ;
	else if (line[0] == '\n' && !ori->inside_map)
		return ;
	else
		(ft_putstr_fd("Error de parsing\n", 2), brexit(ori));
	if (ori->nb_start > 1)
		(ft_putstr_fd("Error KAGEBUNSHIN NO JUSTU ???\n", 2), brexit(ori));
}

// void	parsing_map(t_ori *ori)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	while (1)
// 	{
// 		line = get_next_line(ori->fd);
// 		i++;
// 		if (!line)
// 			break ;
// 		parse_line(ori, line, i);
// 		free(line);
// 	}
// 	if (close(ori->fd) < 0)
// 		(ft_putstr_fd("Error cannot close fd\n", 2), brexit(ori));
// 	// Set ori->nb_line to the total number of lines parsed
//     ori->nb_line = i;
// }

void	parsing_map(t_ori *ori)
{
	char	*line;
	int		i;
	int		map_line_count;

	i = 0;
	map_line_count = 0;
    ori->map_start_line = 0;
    ori->parsed_c = 0;
    ori->parsed_f = 0;
	while (1)
	{
		line = get_next_line(ori->fd);
		if (!line)
			break ;
		i++;
		parse_line(ori, line, i);
		if (i >= ori->map_start_line)
			map_line_count++;
		free(line);
	}
	if (close(ori->fd))
		(ft_putstr_fd("Error cant close fd\n", 2), brexit(ori));
	ori->nb_line = map_line_count;
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

//TEST FUNCTION
// void printf_map(char **map)
// {
// 	int i = 0;
// 	while (map[i])
// 	{
// 		int k = 0;
// 		while (map[i][k])
// 		{
// 			if (map[i][k])
// 				printf("[%c] ", map[i][k]);
// 			else if (map[i][k] == '\n')
// 				printf("[retour ligne] ");
// 			else
// 			printf("[] ");
// 			k++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }
