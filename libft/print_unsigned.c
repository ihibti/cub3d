/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:13:43 by ihibti            #+#    #+#             */
/*   Updated: 2023/12/29 12:18:06 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unsi(unsigned int number)
{
	int	count;

	count = 0;
	put_unsigned(number, &count);
	return (count);
}

void	put_unsigned(unsigned int number, int *count)
{
	if (number < 10)
	{
		ft_printchar(number + '0');
		*count += 1;
	}
	else
	{
		put_unsigned((number / 10), count);
		ft_printchar(((number % 10) + '0'));
		*count += 1;
	}
}

void	put_uint(uint64_t number, int *count)
{
	char	table[17];

	ft_strlcpy(table, "0123456789abcdef", 17);
	if (number < 16)
	{
		ft_printchar(table[number]);
		*count += 1;
	}
	else
	{
		put_uint((number / 16), count);
		ft_printchar((table[number % 16]));
		*count += 1;
	}
}

int	print_ptr(void *ptr)
{
	uint64_t	ret;
	int			count;

	if (!ptr)
	{
		ft_printsr("(nil)");
		return (5);
	}
	ret = (uint64_t)ptr;
	count = 2;
	ft_printsr("0x");
	put_uint(ret, &count);
	return (count);
}
