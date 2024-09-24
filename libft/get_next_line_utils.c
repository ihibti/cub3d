/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:55:07 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/24 17:09:02 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*return_manag(char **acquired, char **ret)
// {
// 	if (*acquired)
// 		free(*acquired);
// 	if (ret[0][0])
// 		return (*ret);
// 	else if (*ret)
// 		free(*ret);
// 	return (NULL);
// }

// char	*rest_manager(char *reste, char *ret)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (pos_nl(reste) < 0)
// 	{
// 		while (reste[i++])
// 			ret[i - 1] = reste[i - 1];
// 		reste[0] = 0;
// 		ret[i - 1] = 0;
// 		return (ret);
// 	}
// 	while (reste[i] && (reste[i] != '\n'))
// 	{
// 		ret[i] = reste[i];
// 		i++;
// 	}
// 	ret[i++] = '\n';
// 	ret[i] = '\0';
// 	while (reste[i + j++])
// 		reste[j - 1] = reste[i + j - 1];
// 	reste[j - 1] = '\0';
// 	return (ret);
// }

// char	*distrib(char *ret, char *reste, char *acquired)
// {
// 	char	*tmp;
// 	int		i;
// 	int		j;

// 	j = 0;
// 	i = 0;
// 	tmp = malloc(BUFFER_SIZE + 1);
// 	if (!tmp)
// 		return (NULL);
// 	while (acquired[i] && (acquired[i] != '\n'))
// 	{
// 		tmp[i] = acquired[i];
// 		i++;
// 	}
// 	tmp[i++] = '\n';
// 	tmp[i] = '\0';
// 	ret = re_alloc(ret, tmp);
// 	if (!ret)
// 		return (NULL);
// 	while (acquired[i + (j++)])
// 		reste[j - 1] = acquired[i + j - 1];
// 	reste[j - 1] = '\0';
// 	free(tmp);
// 	return (ret);
// }

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len;
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * (len) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i++] = s2[j++];
	}
	new[i] = '\0';
	free(s1);
	return (new);
}
