/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:34:42 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/13 17:48:16 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedchar)
{
	int		i;
	char	*ret;

	searchedchar = searchedchar % 256;
	ret = (char *)string;
	i = 0;
	while (string[i])
		i++;
	while (i >= 0)
	{
		if (ret[i] == searchedchar)
			return (&ret[i]);
		i--;
	}
	return (NULL);
}
