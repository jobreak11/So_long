/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:00:03 by gyeepach          #+#    #+#             */
/*   Updated: 2024/11/17 22:04:45 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		digit;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			error();
		digit = *str - '0';
		if ((sign == 1 && (result > (INT_MAX - digit) / 10))
			|| (sign == -1 && (result > ((long)INT_MAX + 1 - digit) / 10)))
			error();
		result = result * 10 + digit;
		str++;
	}
	return ((int)result * sign);
}
