/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:33:25 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/17 15:19:02 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		j;
	const char	*s;
	char		*d;
	int			i;

	i = 0;
	d = dest;
	s = src;
	j = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (j < n)
	{
		d[i] = s[i];
		j++;
		i++;
	}
	return (dest);
}
