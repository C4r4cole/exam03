/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:58:00 by fmoulin           #+#    #+#             */
/*   Updated: 2025/09/01 19:09:20 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char	*s)
{
	int	i;
	
	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;
	
	if (!s1 || !s2)
		return (1);
	i = -1;
	while (n && s1[++i] && s2[i] && s1[i] == s2[i])
		n--;
	return (s1[i] - s2[i]);
}

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

int	filter(char *keyword)
{
	char 	result[1000000];
	char 	buf[100000];
	int		n;
	int		i;

	result[0] = '\0';
	while (1)
	{
		n = read(0, buf, 5);
		if (n == -1)
			return (0);
		if (n == 0)
			break ;
		buf[n] = '\0';
		ft_strcat(result, buf);
	}
	i = 0;
	while (result[i])
	{
		n = 0;
		if (!ft_strncmp(&result[i], keyword, ft_strlen(keyword)))
			while (n < ft_strlen(keyword))
			{
				result[i] = '*';
				i++;
				n++;
			}
		else
			i++;
	}
	puts(result);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	filter(argv[1]);
	return (0);
}