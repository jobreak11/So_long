/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:00:23 by gyeepach          #+#    #+#             */
/*   Updated: 2024/02/29 10:57:34 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_len(int number)
{
	int	len;

	len = 0;
	if (number < 1)
		len++;
	while (number)
	{
		number /= 10;
		len++;
	}
	return (len);
}

static long long	abs_val(long long n)
{
	long long	checking;

	checking = 1;
	if (n < 0)
		checking *= -n;
	else
		checking *= n;
	return (checking);
}

static char	*create_string(size_t n)
{
	char	*str;

	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	number;
	char			*str;
	int				sign;
	int				len;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		sign = 1;
	len = number_len(n);
	str = create_string(len);
	if (!str)
		return (NULL);
	*(str + len) = '\0';
	number = abs_val(n);
	while (len--)
	{
		*(str + len) = number % 10 + '0';
		number /= 10;
	}
	if (sign)
		*(str) = '-';
	return (str);
}
