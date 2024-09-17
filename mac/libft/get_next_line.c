/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:03:15 by ihibti            #+#    #+#             */
/*   Updated: 2023/12/29 12:28:44 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*ret;
	char		*acquired;
	static char	reste[BUFFER_SIZE + 1];

	ret = NULL;
	acquired = NULL;
	if (init_gnl(&ret, &acquired, &fd, reste) == -1)
		return (NULL);
	if (pos_nl(ret) >= 0)
		return (return_manag(&acquired, &ret));
	while (acquisition(acquired, fd) > 0)
	{
		if (pos_nl(acquired) < 0)
			ret = re_alloc(ret, acquired);
		else
		{
			ret = distrib(ret, reste, acquired);
			return (return_manag(&acquired, &ret));
		}
		if (!ret)
			return (NULL);
	}
	return (return_manag(&acquired, &ret));
}

int	acquisition(char *acquired, int fd)
{
	int	nb_bytes;

	nb_bytes = read(fd, acquired, BUFFER_SIZE);
	if (nb_bytes < 0)
		return (-1);
	if (nb_bytes == 0)
		return (0);
	acquired[nb_bytes] = '\0';
	return (nb_bytes);
}

int	pos_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	init_gnl(char **ret, char **acquired, int *fd, char *reste)
{
	int	i;

	i = 0;
	if (*fd < 0)
		return (-1);
	*acquired = malloc(BUFFER_SIZE + 1);
	if (!(*acquired))
		return (-1);
	*ret = malloc(BUFFER_SIZE + 1);
	if (!(*ret))
	{
		free(*acquired);
		return (-1);
	}
	*ret[0] = '\0';
	*acquired[0] = '\0';
	if (reste[i])
	{
		rest_manager(reste, *ret);
	}
	return (0);
}

char	*re_alloc(char *ret, char *acquired)
{
	char	*ret_alloc;
	char	*free_ptr;

	free_ptr = ret;
	if (acquired[0] == 0)
		return (NULL);
	if (ret[0] == '\0')
	{
		ret_alloc = ft_strdup(acquired);
		if (!ret_alloc)
			return (NULL);
		ret = ret_alloc;
		free(free_ptr);
		return (ret_alloc);
	}
	ret_alloc = ft_strjoin(ret, acquired);
	if (!ret_alloc)
		return (NULL);
	ret = ret_alloc;
	free(free_ptr);
	return (ret_alloc);
}
