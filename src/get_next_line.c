/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:12:47 by gyeepach          #+#    #+#             */
/*   Updated: 2025/01/22 19:08:28 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"

void	clean_list(t_word_list **list)
{
	t_word_list	*last_node;
	t_word_list	*clean_node;
	int			i;
	int			j;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_word_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->data[i] && last_node->data[i] != '\n')
		++i;
	while (last_node->data[i] && last_node->data[++i])
		buf[j++] = last_node->data[i];
	buf[j] = '\0';
	clean_node->data = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

char	*get_new_line(t_word_list *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	connect_word_list(t_word_list **list, char *buf)
{
	t_word_list	*new_node;
	t_word_list	*last_node;

	new_node = malloc(sizeof(t_word_list));
	if (new_node == NULL)
	{
		free(buf);
		return ;
	}
	last_node = find_last_node(*list);
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->data = buf;
	new_node->next = NULL;
}

char	create_list(t_word_list **list, int fd)
{
	int		already_read;
	char	*buf;

	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return (0);
		already_read = read(fd, buf, BUFFER_SIZE);
		if (!already_read)
		{
			free(buf);
			buf = NULL;
			return (0);
		}
		if (already_read < 0)
		{
			free(buf);
			buf = NULL;
			return (1);
		}
		buf[already_read] = '\0';
		connect_word_list(list, buf);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_word_list	*list = NULL;
	char				*next_line;
	t_word_list			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (create_list(&list, fd))
	{
		while (list)
		{
			temp = list->next;
			free(list->data);
			free(list);
			list = temp;
		}
		return (NULL);
	}
	if (list == NULL)
		return (NULL);
	next_line = get_new_line(list);
	clean_list(&list);
	return (next_line);
}
