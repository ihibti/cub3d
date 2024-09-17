/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:39:38 by ihibti            #+#    #+#             */
/*   Updated: 2023/12/29 12:17:38 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	init_printf(&i, &len);
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if ((format[i] == '%') && (format[i + 1] == '\0'))
			return (ft_putchar_fd('%', 1), -1);
		else if ((format[i] == '%') && (format[i + 1] == '%'))
		{
			len += ft_printchar('%');
			i++;
		}
		else if ((format[i] == '%'))
			len += ft_distrib(args, format[i++ + 1]);
		else
			len += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

void	init_printf(int *i, int *len)
{
	*i = 0;
	*len = 0;
}
