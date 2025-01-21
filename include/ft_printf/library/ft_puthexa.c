/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:24:57 by gyeepach          #+#    #+#             */
/*   Updated: 2024/04/24 17:33:24 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexa(unsigned long long n, int base)
{
	int		i;
	char	c;

	i = 0;
	if (n >= 16)
	{
		i += ft_puthexa(n / 16, base);
		i += ft_puthexa(n % 16, base);
	}
	else
	{
		if (n < 10)
		{
			c = n + '0';
			i += write(1, &c, 1);
		}
		else
		{
			if (base)
				i += write(1, &"0123456789ABCDEF"[n % 16], 1);
			else
				i += write(1, &"0123456789abcdef"[n % 16], 1);
		}
	}
	return (i);
}
