/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:42:58 by gyeepach          #+#    #+#             */
/*   Updated: 2024/03/01 08:08:54 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*ss1;
	unsigned char		*ss2;

	if (n == 0)
		return (0);
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		if (n)
		{
			ss1++;
			ss2++;
		}
	}
	return (0);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[20] = "Hello Hi lo";
// 	char	s2[20] = "Help Hi lo";
// 	size_t	n;

// 	n = 14;
// 	printf("mem %d\n", memcmp(s1, s2, n));
// 	printf("ft %d\n", ft_memcmp(s1, s2, n));
// 	return (0);
// }
