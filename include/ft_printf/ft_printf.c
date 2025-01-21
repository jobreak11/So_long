/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:13:35 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/20 19:42:42 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char type, va_list ap)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (type == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (type == 'p')
		count += ft_putaddress((va_arg(ap, void *)));
	else if (type == 'x')
		count += ft_puthexa((va_arg(ap, unsigned int)), 0);
	else if (type == 'X')
		count += ft_puthexa((va_arg(ap, unsigned int)), 1);
	else if (type == 'd' || type == 'i')
		count += ft_putnbr((va_arg(ap, int)));
	else if (type == 'u')
		count += ft_putunsigned(va_arg(ap, unsigned int));
	else
		count += write(1, &type, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*format == '%')
				count += ft_print_format(*(++format), ap);
			else if (*format != '\0')
				count += write(1, format, 1);
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

