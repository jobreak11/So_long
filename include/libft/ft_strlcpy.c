/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:55:48 by gyeepach          #+#    #+#             */
/*   Updated: 2024/03/01 08:08:13 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;

	len_src = 0;
	if (size)
	{
		while (src[len_src] && len_src < size - 1)
		{
			dst[len_src] = src[len_src];
			len_src++;
		}
		dst[len_src] = '\0';
	}
	return (ft_strlen(src));
}
// completed
//  int	main()
//  {
//  	char dst[20] = "Hello";
//  	char src[20] = "Peerapol Srisawat";
//  	int r;

// 	r = ft_strlcpy(dst, src, 3);
// 	printf("%s || %s || %d\n", dst, src, r);
// }
