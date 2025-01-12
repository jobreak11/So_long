/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:30:21 by gyeepach          #+#    #+#             */
/*   Updated: 2024/02/29 11:36:10 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	trimmed_length;
	size_t	i;
	char	*trimmed;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	trimmed_length = end - start;
	trimmed = (char *)malloc(trimmed_length + 1);
	if (trimmed == NULL)
		return (NULL);
	while (i < trimmed_length)
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	trimmed[trimmed_length] = '\0';
	return (trimmed);
}
// #include <stdio.h>

// int	main()
// {
// 	char	str[] = "|*Gongtup**Yeepacha|*";
// 	char	ch[] = "*|";
// 	char	*ret;

// 	ret = ft_strtrim(str, ch);
// 	printf("%s", ret);

// }
