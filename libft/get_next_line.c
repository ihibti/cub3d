/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:03:15 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/26 16:47:20 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_buffer(char *buff)
{
	free(buff);
	return (NULL);
}

static char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
/* 	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n'; */

static char	*ft_get_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free_buffer(buffer));
	line = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

static void	*ft_read_file(int fd, char *res)
{
	char	*buffer;
	int		n_byte;

	if (!res)
	{
		res = malloc(1);
		if (res)
			res[0] = '\0';
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	n_byte = 1;
	while (n_byte > 0)
	{
		n_byte = read(fd, buffer, BUFFER_SIZE);
		if (n_byte == -1)
			return (free_buffer(buffer));
		buffer[n_byte] = '\0';
		res = ft_strjoin_gnl(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_get_next_line(buffer);
	return (line);
}

// char	*get_next_line(int fd)
// {
// 	char		*ret;
// 	char		*acquired;
// 	static char	reste[BUFFER_SIZE + 1];

// 	ret = NULL;
// 	acquired = NULL;
// 	if (init_gnl(&ret, &acquired, &fd, reste) == -1)
// 		return (NULL);
// 	if (pos_nl(ret) >= 0)
// 		return (return_manag(&acquired, &ret));
// 	while (acquisition(acquired, fd) > 0)
// 	{
// 		if (pos_nl(acquired) < 0)
// 			ret = re_alloc(ret, acquired);
// 		else
// 		{
// 			ret = distrib(ret, reste, acquired);
// 			return (return_manag(&acquired, &ret));
// 		}
// 		if (!ret)
// 			return (NULL);
// 	}
// 	return (return_manag(&acquired, &ret));
// }

// int	acquisition(char *acquired, int fd)
// {
// 	int	nb_bytes;

// 	nb_bytes = read(fd, acquired, BUFFER_SIZE);
// 	if (nb_bytes < 0)
// 		return (-1);
// 	if (nb_bytes == 0)
// 		return (0);
// 	acquired[nb_bytes] = '\0';
// 	return (nb_bytes);
// }

// int	pos_nl(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\n')
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// int	init_gnl(char **ret, char **acquired, int *fd, char *reste)
// {
// 	int	i;

// 	i = 0;
// 	if (*fd < 0)
// 		return (-1);
// 	*acquired = malloc(BUFFER_SIZE + 1);
// 	if (!(*acquired))
// 		return (-1);
// 	*ret = malloc(BUFFER_SIZE + 1);
// 	if (!(*ret))
// 	{
// 		free(*acquired);
// 		return (-1);
// 	}
// 	*ret[0] = '\0';
// 	*acquired[0] = '\0';
// 	if (reste[i])
// 	{
// 		rest_manager(reste, *ret);
// 	}
// 	return (0);
// }

// char	*re_alloc(char *ret, char *acquired)
// {
// 	char	*ret_alloc;
// 	char	*free_ptr;

// 	free_ptr = ret;
// 	if (acquired[0] == 0)
// 		return (NULL);
// 	if (ret[0] == '\0')
// 	{
// 		ret_alloc = ft_strdup(acquired);
// 		if (!ret_alloc)
// 			return (NULL);
// 		ret = ret_alloc;
// 		free(free_ptr);
// 		return (ret_alloc);
// 	}
// 	ret_alloc = ft_strjoin(ret, acquired);
// 	if (!ret_alloc)
// 		return (NULL);
// 	ret = ret_alloc;
// 	free(free_ptr);
// 	return (ret_alloc);
// }