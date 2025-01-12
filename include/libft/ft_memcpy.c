/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:45:26 by gyeepach          #+#    #+#             */
/*   Updated: 2024/03/01 08:08:48 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*source;

	i = 0;
	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}
// #include <stdio.h>

// int	main()
// {
// // 	char dest[30] = "Peerapol Boat Srisawat";
// // 	char src[30] = "IT";

// // 	printf("Before : %s\n", dest);
// // 	memcpy(dest, src, 3);
// // 	printf("Memcpy : %s\n", dest);

// // 	ft_memcpy(dest, src, 3);
// // 	printf("ft_memcpy : %s", dest);

// 	char	str[100] = "Learningisfun";
// 	char	*first, *second;

// 	first = str;
// 	second = str;
// 	printf("Original String   : %s\n", str);

// 	ft_memcpy(second + 8, first, 10);
// 	printf("ft_memcpy overlap : %s\n", str);
// }
