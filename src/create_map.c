#include "cub3d.h"

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
	ori->map = malloc(sizeof(char *) * (ori->nb_line + 1));
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
			if (i >= ori->nb_line)
				(ft_putstr_fd("Error: Exceeded map size\n", 2), brexit(ori));
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
    // for (int j = 0; ori->map[j];j++)
    //     printf("%s\n",ori->map[j]);
}
