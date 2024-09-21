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
	int	current_len;

	i = 0;
	len = 0;
	while (map[i])
	{
		current_len = ft_strlen(map[i]);
		if (current_len > len)
			len = current_len;
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
		if (!line)
			break ;
		j++;
		if (j >= ori->map_start_line)
		{
			ori->map[i] = ft_strdup(line);
			if (!ori->map[i])
				(ft_putstr_fd("Error ft_strdup\n", 2), brexit(ori));
			i++;
		}
		free(line);
	}
	ori->map[i] = NULL;
	ori->map_height = i;
	ori->map_width = find_longest_line(ori->map);
	if (close(ori->fd) < 0)
		(ft_putstr_fd("Error close fd\n", 2), brexit(ori));
}
