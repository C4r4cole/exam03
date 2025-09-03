/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:22:50 by fmoulin           #+#    #+#             */
/*   Updated: 2025/09/03 18:01:13 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_00.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static void shift_buf(char *buf, int n)
{
	int i;

	i = 0;
	while (buf[n])
	{
		buf[i] = buf[n];
		i++;
		n++;
	}
	buf[i] = '\0';
}

static char *strjoin_gnl(char *line, char *buf, int n)
{
	char	*appended;
	int		i;
	int		j;

	appended = malloc(sizeof(char) * (ft_strlen(line) + n + 1));
	if (!appended)
		return (free(line), NULL);
	i = 0;
	while (line && line[i])
	{
		appended[i] = line[i];
		i++;
	}
	j = 0;
	while (j < n && buf[j])
	{
		appended[i] = buf[j];
		i++;
		j++;
	}
	appended[i] = '\0';
	free(line);
	return (appended);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			char_read;
	int			i;
	
	line = NULL;
	while (1)
	{
		if (!*buf)
		{
			char_read = read(fd, buf, BUFFER_SIZE);
			if (char_read <= 0)
				return (line);
			buf[char_read] = '\0';
		}
		i = 0;
		while (buf[i] && buf[i] != '\n')
			i++;
		line = strjoin_gnl(line, buf, i + (buf[i] == '\n'));
		if (buf[i] == '\n')
			return (shift_buf(buf, i + 1), line);
		*buf = 0;		
	}
}

int	main(void)
{
	int		fd;
	char 	*line;
	int		nbr_line;

	fd = open("file.txt", O_RDONLY);
	nbr_line = 1;
	while ((line = get_next_line(fd)))
	{
		printf("%d -> %s", nbr_line, line);
		nbr_line++;
		free(line);
	}
	return (0);
}