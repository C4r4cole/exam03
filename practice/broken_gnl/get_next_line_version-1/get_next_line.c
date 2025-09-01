/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:30:30 by fmoulin           #+#    #+#             */
/*   Updated: 2025/08/29 10:47:49 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(t_list *list)
{
	int i;
	
	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_list	*get_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}

void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;
	
	new_node = malloc(sizeof(t_list));
	last_node = get_last_node(*list);
	if (new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	char	*buf;
	int		char_read;

	while (!is_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == 0)
		{
			free(buf);
			return ;
		}
		if (char_read == -1)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append(list, buf);
	}
}

int	len_to_new_line(t_list *list)
{
	int	i;
	int len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (i);
}

void	copy_str(t_list *list, char	*str)
{
	int	i;
	int	j;
	
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				str[j] = '\n';
				j++;
				str[j] = '\0';
				return ;
			}
			str[j] = list->str_buf[i];
			i++;
			j++;
		}
		list = list->next;
	}
	str[j] = '\0';
}

char	*get_appended_list(t_list *list)
{
	int		str_len;
	char	*next_str;
	
	str_len = len_to_new_line(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	clean_list(t_list *list)
{
	t_list	*last_node;
	t_list	*clean_node;
	char	*buf;
	
	last_node = get_last_node(list);
	clean_node = malloc(sizeof(t_list));
	if (!clean_node)
		return ;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	i = 0
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char	*next_line;
	
	next_line = 0;
	create_list(&list, fd);
	next_line = get_appended_list(list);
	// clean_list(&list); //TODO
	return (next_line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		counter;

	fd = open("file.txt", O_RDONLY);
	counter = 1;
	while ((line = get_next_line(fd)))
	{
		printf("%d -> %s\n", counter, line);
		counter++;
		free(line);
	}
	return (0);
}