/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:34:38 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/20 14:30:29 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t size)
{
	size_t	i;
	size_t	j;
	char	*ret;

	ret = (char *)big;
	i = 0;
	j = 0;
	if ((small == NULL && big == NULL) || (big == NULL && size == 0))
		return (ret);
	if (small[0] == '\0')
		return (ret);
	while (big[i] && (i < size))
	{
		while ((big[i + j] == small[j]) && ((i + j) < size))
		{
			if (small[j + 1] == '\0')
				return (&ret[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char haystack[30] = "aaabcabcd";
// 	char needle[10] = "aabc";
// 	printf("%s\n", ft_strnstr(haystack, needle, 0));
// }