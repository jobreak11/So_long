/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:25:51 by gyeepach          #+#    #+#             */
/*   Updated: 2024/02/28 20:33:41 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*s1 || *s2) && n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}

// int	main()
// {
// 	char	s1[20] = "Hello Hi lo";
// 	char	s2[20] = "Help Hi lo";
// 	size_t	n;

// 	n = 14;
// 	printf("mem %d\n", strncmp(s1, s2, n));
// 	printf("ft %d\n", ft_strncmp(s1, s2, n));
// }
