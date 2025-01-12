/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:08:16 by gyeepach          #+#    #+#             */
/*   Updated: 2024/02/28 22:15:05 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = (char *)malloc(len + 1 * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[start++];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// char    *ft_substr(const char *s, unsigned int start, size_t len)
// {
//     char    *res;
//     size_t    end;
//     size_t    i;

//     i = 0;
//     start = 0;
//     if (!s)
//         return (0);
//     if (start > strlen(s))
//         return (ft_strdup(""));
//     end = strlen(s) + start;
//     if (len > strlen(s) - start)
//         len = strlen(s) - start;
//     res = (char *)malloc(len + 1 * sizeof(char));
//     if (!res)
//         return (NULL);
//     while (end > i)
//         res[start++] = s[len++ - 4];
//         i++;
//     return (res);
// }
// not tested yet

// int main ()
// {
//     char *a = "asdasjklklklkjkjlasd";
//     printf("%s\n", ft_substr(a, 7, 10));
// }
