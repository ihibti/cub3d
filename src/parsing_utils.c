#include "cub3d.h"

void	open_file(t_ori *ori)
{
	ori->fd = open(ori->file, O_RDONLY);
	if (ori->fd < 0)
	{
		printf("Error\nFile not found\n");
		exit(0);
	}
}

void	check_file(t_ori *ori)
{
	ori->fd = open(ori->file, __O_DIRECTORY);
	if (ori->fd != -1)
	{
		close(ori->fd);
		exit_game(ori, "Error file\n", NULL);
	}
}

void	valid_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len >= 5 && ft_strcmp(str + len - 4, ".cub") == 0)
		return ;
	else
	{
		ft_putstr_fd("Error\nInvalid arg\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	check_comma(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	if (!ft_isdigit(line[i]))
		return (1);
	while (line[i])
	{
		if (line[i] == ',' && line[i + 1] && ft_isdigit(line[i + 1]))
			comma++;
		if (!ft_isdigit(line[i]) && line[i] != ',')
			return (1);
		i++;
	}
	if (comma == 2)
		return (0);
	return (1);
}