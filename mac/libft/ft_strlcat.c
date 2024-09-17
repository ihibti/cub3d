/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:34:22 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/20 14:28:56 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strlcat(char *destination, const char *src, int l)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	i = 0;
// 	while (destination[i])
// 		i++;
// 	while (src[j] && j < l)
// 	{
// 		destination[i + j] = src[j];
// 		j++;
// 	}
// 	destination[i + j] = '\0';
// 	return (destination);
// }

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_size;
	size_t	s_size;
	size_t	i;

	if (((src == NULL && dest == NULL)) || ((dest == NULL) && size == 0))
		return (size);
	d_size = 0;
	s_size = 0;
	i = 0;
	while (dest[d_size] && d_size < size)
		d_size++;
	while (src[s_size])
		s_size++;
	if (size <= d_size || size == 0)
		return (size + s_size);
	while (src[i] && d_size + i < size - 1)
	{
		dest[d_size + i] = src[i];
		i++;
	}
	dest[d_size + i] = '\0';
	return (d_size + s_size);
}
