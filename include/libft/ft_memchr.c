/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:41:16 by gyeepach          #+#    #+#             */
/*   Updated: 2024/02/28 20:30:46 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	chr;

	temp = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n--)
	{
		if (*temp == chr)
			return (temp);
		temp++;
	}
	return (0);
}

// int	main()
// {
// 	char	str[] = "Peerapol Boat Srisawat";
// 	int		ch = ' ';
// 	char	*re;
// 	char	*re_ft;

// 	// re = memchr(str, ch, 2);
// 	// printf("%s\n", re);

// 	re_ft = ft_memchr(str, ch, 2);
// 	printf("%s", re_ft);

// }
// not completed yet

// int main(void)
// {

// 	char s[] = {0, 1, 2 ,3 ,4 ,5};
// 	printf("%s\n", ft_memchr(s, 0, 0));//== NULL
// 	printf("%s\n", ft_memchr(s, 0, 1));//== s
// 	printf("%s\n", ft_memchr(s, 2, 3));//== s + 2
// 	printf("%s\n", ft_memchr(s, 6, 6));//== NULL
// 	printf("%s\n", ft_memchr(s, 2 + 256, 3));//== s + 2
// 	return (0);
// }
