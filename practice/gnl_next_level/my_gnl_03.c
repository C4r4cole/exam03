/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_gnl_03.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:03:24 by fmoulin           #+#    #+#             */
/*   Updated: 2025/09/01 16:36:58 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_gnl.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static void	shift_buf(char *buf, int n)
{
	int	i;

	i = 0;
	while (buf[n])
	{
		buf[i] = buf[n];
		i++;
		n++;
	}
	buf[i] = '\0';
}

static char *strjoin_gnl(char *s1, char *s2, int n)
{
	char	*appended;
	int		i;
	int		j;

	appended = malloc(sizeof(char) * (ft_strlen(s1) + n + 1));
	if (!appended)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		appended[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < n && s2[j])
	{
		appended[i] = s2[j];
		i++;
		j++;
	}
	appended[i] = '\0';
	free(s1);
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
	int		nbr_line;
	char	*line;

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