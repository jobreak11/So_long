/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:25:38 by gyeepach          #+#    #+#             */
/*   Updated: 2024/04/22 19:53:32 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putaddress(void *p)
{
	int	i;

	i = 0;
	if (p == 0)
		return (write(1, "(nil)", 5));
	i += write(1, "0x", 2);
	i += ft_puthexa((unsigned long long)p, 0);
	return (i);
}
