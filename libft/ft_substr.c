/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:34:52 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/20 13:18:11 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	decision(size_t *size, size_t *len, unsigned int *start);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			size;
	char			*ptr;

	if (s == NULL)
		return (NULL);
	size = (size_t)ft_strlen(s);
	decision(&size, &len, &start);
	ptr = malloc(size + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] && i < size)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	decision(size_t *size, size_t *len, unsigned int *start)
{
	if (*start < *size)
	{
		if (*len > (*size - *start))
			*size = *size - *start;
		else
			*size = *len;
	}
	else
		*size = 0;
}
