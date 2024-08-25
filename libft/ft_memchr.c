/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:04:57 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/13 16:57:26 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	int		offset;
	size_t	i;
	void	*ret;
	char	*ptr;

	searchedChar = searchedChar % 256;
	ret = (void *)memoryBlock;
	i = 0;
	offset = 0;
	ptr = (char *)memoryBlock;
	while (i < size)
	{
		if (ptr[i] == searchedChar)
			return (ret + offset);
		i += 1;
		offset += 1;
	}
	return (NULL);
}
