/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:44:32 by ihibti            #+#    #+#             */
/*   Updated: 2023/12/29 12:17:31 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printsr(char *str)
{
	if (!str)
		return (ft_printsr("(null)"));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_printchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

void	ft_pri_sign(int number, int *count)
{
	long	nbr;

	nbr = number;
	if (nbr < 0)
	{
		write(1, "-", 1);
		*count += 1;
		nbr *= -1;
	}
	if (nbr < 10)
	{
		ft_printchar(nbr + '0');
		*count += 1;
	}
	else
	{
		ft_pri_sign((nbr / 10), count);
		ft_printchar(((nbr % 10) + '0'));
		*count += 1;
	}
}

void	conv_hex(int n, int *count, int flag)
{
	unsigned int	nbr;
	char			base_c[17];
	char			base_l[17];

	ft_strlcpy(base_c, "0123456789ABCDEF", 17);
	ft_strlcpy(base_l, "0123456789abcdef", 17);
	nbr = (unsigned int)n;
	if (nbr < 16)
	{
		if (flag == 1)
			ft_printchar(base_l[nbr]);
		else
			ft_printchar(base_c[nbr]);
		*count += 1;
	}
	else
	{
		conv_hex((nbr / 16), count, flag);
		if (flag == 1)
			ft_printchar(base_l[nbr % 16]);
		else
			ft_printchar(base_c[nbr % 16]);
		*count += 1;
	}
}

int	ft_distrib(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_printsr(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
	{
		ft_pri_sign(va_arg(args, int), &count);
		return (count);
	}
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			conv_hex(va_arg(args, unsigned int), &count, 1);
		else
			conv_hex(va_arg(args, unsigned int), &count, 0);
		return (count);
	}
	else if (c == 'u')
		return (print_unsi(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (print_ptr(va_arg(args, void *)));
	return (1);
}
