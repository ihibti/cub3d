/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:34:04 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/13 17:59:30 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedchar)
{
	char	*str;
	int		i;

	searchedchar = searchedchar % 256;
	i = 0;
	str = (char *)string;
	while (str[i])
	{
		if (str[i] == searchedchar)
			return ((char *)str);
		str++;
	}
	if (str[i] == searchedchar)
		return (&str[i]);
	return (NULL);
}
