/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:24:03 by gyeepach          #+#    #+#             */
/*   Updated: 2024/04/24 17:33:42 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n)
{
	int	res;

	res = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		res += ft_putchar('-');
		res += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		res += ft_putnbr(n / 10);
		res += ft_putchar(n % 10 + '0');
	}
	else if (n >= 0 && n < 10)
		res += ft_putchar(n + '0');
	return (res);
}
