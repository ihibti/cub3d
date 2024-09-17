/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:33:29 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/17 17:10:49 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memmove(void *dest, const void *src, size_t size)
// {
// 	char		*d;
// 	const char	*s;
// 	size_t		i;

// 	if (src == NULL)
// 		return (NULL);
// 	d = (char *)dest;
// 	s = (const char *)src;
// 	if (d > s)
// 	{
// 		i = size - 1;
// 		while (i >= 0)
// 		{
// 			d[i] = s[i];
// 			i -= 1;
// 		}
// 	}
// 	else
// 	{
// 		i = 0;
// 		while (i < size)
// 		{
// 			d[i] = s[i];
// 			i += 1;
// 		}
// 	}
// 	return (dest);
// }

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t		i;
	char		*c_dest;
	const char	*c_src;

	i = 0;
	c_dest = (char *)dest;
	c_src = (char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (src < dest)
	{
		i = size;
		while (i > 0)
		{
			c_dest[i - 1] = c_src[i - 1];
			i--;
		}
		return (dest);
	}
	while (i < size)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}
