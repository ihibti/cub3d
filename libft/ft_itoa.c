/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:33:16 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/20 15:23:08 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_itoa(int *len, char **ret, long *num, int *min);

char	*ret_ptr(int n)
{
	char	*ret;

	ret = malloc((n + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	return (ret);
}

int	len_ptr(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len += 1;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;
	long	num;
	int		min;

	num = n;
	init_itoa(&len, &ret, &num, &min);
	if (!ret)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		ret[0] = '-';
		min = 1;
	}
	ret[len--] = '\0';
	if (num == 0)
		ret[0] = '0';
	while (len >= min)
	{
		ret[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (ret);
}

void	init_itoa(int *len, char **ret, long *num, int *min)
{
	*min = 0;
	*len = len_ptr(*num);
	*ret = ret_ptr(*len);
}
