/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:26:16 by gyeepach          #+#    #+#             */
/*   Updated: 2024/02/29 12:24:04 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (!dest && !src)
		return (0);
	if (ptr_dest > ptr_src)
	{
		while (n--)
			ptr_dest[n] = ptr_src[n];
	}
	if (ptr_dest < ptr_src)
	{
		while (n--)
			*ptr_dest++ = *ptr_src++;
	}
	return (dest);
}
