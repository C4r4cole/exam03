/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_n_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:37:46 by ale-coss          #+#    #+#             */
/*   Updated: 2025/08/29 14:27:26 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_n_l.h"

int	ft_len(char *s)
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

static char	*strjoin_gnl(char *s1, char *s2, int n)
{
	char	*new;
	int		i;
	int		j;

	new = malloc((ft_len(s1) + n + 1) * sizeof(char));
	if (!new)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < n && s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			r;

	line = NULL;
	while (1)
	{
		if (!*buf)
		{
			r = read(fd, buf, BUFFER_SIZE);
			if (r <= 0)
				return (line);
			buf[r] = '\0';
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

#include "stdio.h"
#include "fcntl.h"

int main()
{
	int fd = open("file.txt", O_RDONLY);
	char *line;
	int line_nbr;

	line_nbr = 0;
	while ((line = get_next_line(fd)))
	{
		printf("%d -> %s", line_nbr, line);
		line_nbr++;
		free(line);
	}
}
