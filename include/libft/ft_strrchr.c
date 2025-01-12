/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 07:51:59 by gyeepach          #+#    #+#             */
/*   Updated: 2024/02/27 13:48:31 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

// int	main()
// {
// 	char	str[] = "Peerapol Boat Srisawat";
// 	int		ch = ' ';

// 	// printf("Exam: |%s|\n", strrchr(str, ch));

// 	printf("Ans : |%s|", ft_strrchr(str, ch));
// }

// not completed yet
