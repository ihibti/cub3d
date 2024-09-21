#include "cub3d.h"

void	open_fd(t_ori *ori)
{
	ori->fd = open(ori->file, O_RDONLY);
	if (ori->fd == -1)
		(ft_putstr_fd("Error cant open fd\n", 2), brexit(ori));
}

int	find_longest_line(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > len)
			len = ft_strlen(map[i]);
		i++;
	}
	return (len);
}

void	create_map(t_ori *ori)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	ori->map = malloc(sizeof(char *) * (ori->nb_line + 2));
	if (!ori->map)
		(ft_putstr_fd("Error malloc\n", 2), brexit(ori));
	while (1)
	{
		line = get_next_line(ori->fd);
		j++;
		if (!line)
			break ;
		if (j >= ori->map_start_line)
			ori->map[i++] = ft_strdup(line);
		free(line);
	}
	ori->map[i] = NULL;
	ori->map_height = i;
	ori->map_width = find_longest_line(ori->map);
	if (close(ori->fd) < 0)
		(ft_putstr_fd("Error close fd\n", 2), brexit(ori));
}

void	parsing(t_ori *ori)
{
	// open_fd(ori);
	// parsing_map(ori);
	open_fd(ori);
	create_map(ori);
}