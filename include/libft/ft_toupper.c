/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:06:08 by gyeepach          #+#    #+#             */
/*   Updated: 2024/02/29 16:41:13 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
// #include <ctype.h>
// #include <stdio.h>

// int main() {
//    printf("%c\n", toupper('h'));
//    printf("%c\n", ft_toupper('h'));
//    return 0;
// }
