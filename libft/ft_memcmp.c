/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:33:20 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/13 17:39:44 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	size_t		i;
	const char	*un;
	const char	*deux;

	un = ptr1;
	deux = ptr2;
	i = 0;
	while (i < size)
	{
		if (un[i] != deux[i])
			return ((unsigned char)un[i] - ((unsigned char)deux[i]));
		i++;
	}
	return (0);
}
