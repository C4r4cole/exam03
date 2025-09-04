/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:14:38 by fmoulin           #+#    #+#             */
/*   Updated: 2025/09/04 11:39:02 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	ft_strcat(char *result, char *buf)
{
	int i;
	int	j;

	i = 0;
	while (result && result[i])
		i++;
	j = 0;
	while (buf && buf[j])
	{
		result[i] = buf[j];
		i++;
		j++;
	}
	result[i] = '\0';
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int i;

	while (!s1 || !s2)
		return (0);
	i = -1;
	while (n && s1[++i] && s2[i] && s1[i] == s2[i])
		n--;
	return (s1[i] - s2[i]);
}

void	filter(char *keyword)
{
	char	result[1000000];
	char	buf[100000];
	int		i;
	int		n;

	result[0] = '\0';
	while (1)
	{
		n = read(0, buf, 5);
		if (n == -1)
		{
			write(2, "error: coucou", 13);
			return ;
		}
		if (n == 0)
			break;
		buf[n] = '\0';
		ft_strcat(result, buf);
	}
	i = 0;
	while (result[i])
	{
		n = 0;
		if (!ft_strncmp(&result[i], keyword, ft_strlen(keyword)))
		{
			while (n < ft_strlen(keyword))
			{
				result[i] = '*';
				i++;
				n++;
			}
		}
		else
			i++;
	}
	puts(result);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	filter(argv[1]);
	return (0);
}