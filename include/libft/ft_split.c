/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:02:52 by gyeepach          #+#    #+#             */
/*   Updated: 2024/12/13 12:23:48 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	wordcount(const char *s, char c)
{
	size_t	count;
	bool	is_word;

	count = 0;
	while (*s)
	{
		is_word = false;
		while (*s == c)
			++s;
		while (*s != '\0' && *s != c)
		{
			if (!is_word)
			{
				++count;
				is_word = true;
			}
			++s;
		}
	}
	return (count);
}

static int	free_space(char **res, int position, size_t buffer)
{
	int	i;

	i = 0;
	res[position] = malloc(buffer);
	if (res[position] == NULL)
	{
		while (i < position)
			free(res[i++]);
		free(res);
		return (1);
	}
	return (0);
}

static int	put_word(char **res, char const *s, char delimeter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			++s;
		while (*s != delimeter && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (free_space(res, i, len + 1))
				return (1);
			ft_strlcpy(res[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	words_count;
	char	**res;

	if (!s)
		return (0);
	words_count = wordcount(s, c);
	res = malloc((words_count + 2) * sizeof(char *));
	if (!res)
		return (0);
	res[words_count] = NULL;
	if (put_word(res, s, c))
		return (NULL);
	return (res);
}

// static size_t	wordcount(const char *s, char c)
// {
// 	size_t	count;
// 	int		i;
// 	bool	is_word;

// 	count = 0;
// 	i = 0;
// 	is_word = false;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 	{
// 		if (s[i] == c)
// 			is_word = false;
// 		else if (!is_word)
// 		{
// 			is_word = true;
// 			count++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }

// static int	free_space(char **res, int position, size_t buffer)
// {
// 	int i;

// 	i = 0;
// 	if (position < 0)
// 		return (1);
// 	if (res[position] != NULL)
// 		free(res[position]);
// 	res[position] = malloc(buffer);
// 	if (res[position] == NULL)
// 	{
// 		while (i < position)
// 			free(res[i]);
// 		free(res);
// 		return (1);
// 	}
// 	return (0);
// }
// static int	put_word(char **res, char const *s, char delimeter)
// {
// 	size_t	len;
// 	int		i;

// 	i = 0;
// 	if (!s || !res)
// 		return (1);
// 	while (*s)
// 	{
// 		len = 0;
// 		while (*s == delimeter && *s)
// 			++s;
// 		while (*s != delimeter && *s)
// 		{
// 			++len;
// 			++s;
// 		}
// 		if (len)
// 		{
// 			if (free_space(res, i, len + 1))
// 				return (1);
// 			ft_strlcpy(res[i], s - len, len + 1);
// 			i++;
// 		}
// 	}
// 	res[i] = NULL;
// 	return (0);
// }
// void	free_split(char **res, size_t words_count)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!res)
// 		return ;
// 	while (i < words_count)
// 	{
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// }

// 	char	**ft_split(char const *s, char c)
// {
// 	size_t	words_count;
// 	size_t		i;
// 	char	**res;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	words_count = wordcount(s, c);
// 	res = (char **)malloc((words_count + 1) * sizeof(char *));
// 	if (res == NULL)
// 		return (NULL);
// 	while (i <= words_count)
// 	{
// 		res[i] = NULL;
// 		i++;
// 	}
// 	if (put_word(res, s, c))
// 	{
// 		free_split(res, words_count);
// 		return (NULL);
// 	}
// 	return (res);
// }
