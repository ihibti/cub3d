#include "cub3d.h"

void	open_fd(t_ori *ori)
{
	ori->fd = open(ori->file, O_RDONLY);
	if (ori->fd < 0)
	{
		printf("Error\nFile not found\n");
		exit(0);
	}
}

// void	check_file(t_ori *ori)
// {
// 	ori->fd = open(ori->file, __O_DIRECTORY);
// 	if (ori->fd != -1)
// 	{
// 		close(ori->fd);
// 		// exit_game(ori, "Error: trying to open directory, not a file\n",
// NULL);
// 		(ft_putstr_fd("Error trying to open directory\n", 2), brexit(ori));
// 	}
// }

void	valid_extension(t_ori *ori, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len >= 5 && ft_strcmp(str + len - 4, ".cub") == 0)
	{
		ori->file = ft_strdup(str);
		if (!ori->file)
			(brexit(ori));
		return ;
	}
	else
	{
		ft_putstr_fd("Error\nInvalid arg\n", 2);
		ft_putstr_fd(".cub file expected\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	check_comma(char *line)
{
	int i = 0;
	int comma = 0;

	i = jump_space(line);
	if (!line[i])
		return (1);
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
        i++;
	}
	if (comma == 2)
		return (0);
	return (1);
}