/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:34:47 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/17 16:18:49 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_str(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	non_sep_in_str(const char *str, char const *set)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (str[i] == 0)
		return (0);
	while (is_in_str(set, str[i]) == 1 && str[i])
	{
		ret++;
		i++;
		if (ret == ft_strlen(str))
			return (0);
	}
	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (is_in_str(set, str[i]) == 0)
			return (ft_strlen(str) - ret);
		i--;
		ret++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*ret;
	int		j;

	if (!s1)
		return (NULL);
	j = 0;
	i = 0;
	len = ft_strlen(s1);
	while (is_in_str(set, s1[len - 1]) == 1 && len > 0)
		len--;
	ret = malloc((non_sep_in_str(s1, set) + 1));
	if (!ret)
		return (NULL);
	while (is_in_str(set, s1[i]) == 1 && s1[i])
		i++;
	while (s1[i] && (i < len))
	{
		ret[j] = s1[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

// int	main(void)
// {
// 	char *s = ft_strtrim("   xxx   xxx", " x");
// 	printf("%s %d\n", s, ft_strlen(s));
// }