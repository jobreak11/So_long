/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:22:49 by gyeepach          #+#    #+#             */
/*   Updated: 2024/03/01 08:08:41 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)str;
	while (n > 0)
	{
		ptr[n - 1] = c;
		n--;
	}
	return (str);
}
// int main()
// {
// 	// char str1[30] = "Peerapol Boat Srisawat";
// 	// memset(str1 + 15, '.', 6);
// 	// printf("%s\n", str1);

// 	char str[30] = "Peerapol Boat Srisawat";
// 	ft_memset(str + 8, '\0', 6);
// 	printf("%s", str);
// }
