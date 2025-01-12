/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 07:51:31 by gyeepach          #+#    #+#             */
/*   Updated: 2024/03/01 08:08:28 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
// int	main()
// {
// 	const char	str[] = "Peerapol Boat Srisawat";
// 	int	ch = ' ';
// 	char *ret;
// 	char *s;

// 	s = ft_strchr(str, ch);
// 	// ret = strchr(str, ch);

// 	// printf("String After : |%c| is - |%s|\n", ch, ret);
// 	printf("String After : |%c| is - |%s|\n", ch, s);
// }
