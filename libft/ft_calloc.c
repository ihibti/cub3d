/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:32:31 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/17 16:15:54 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_calloc(size_t elementCount, size_t elementsize)
// {
// 	size_t	i;
// 	void	*ptr;
// 	char	*init;

// 	i = 0;
// 	ptr = malloc(elementCount * elementsize);
// 	init = (char *)ptr;
// 	if (!ptr)
// 		return (NULL);
// 	while (i < elementCount)
// 		init[i++] = 0;
// 	return (ptr);
// }

void	*ft_calloc(size_t nbrelem, size_t size)
{
	void	*ptr;

	if (size != 0)
	{
		if (nbrelem > (INT_MAX / size))
			return (0);
	}
	ptr = malloc(nbrelem * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nbrelem * size);
	return (ptr);
}
