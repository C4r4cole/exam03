/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:44:47 by                   #+#    #+#             */
/*   Updated: 2025/09/02 17:52:49 by 		          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str);
int ft_strncmp(char *s1, char *s2, int n);
void ft_strcat(char *dest, char *src);

int filter(char *keyword)
{
	char res[1500000];
	char buf[100000];
	int r;
	int	i;
	int	j;
	int	key_len;
	
	key_len = ft_strlen(keyword);
	res[0] = '\0'; //met un /0 dedans;
	while (1)
	{
		r = read(0, buf, rand() % 10);
		if (r == -1)
		{
			write(2, "Error: read failed\n", 19);
			return (1);
		}
		if (r == 0)
			break ;
		buf[r] = '\0'; //fini la string
		ft_strcat(res, buf);
	}
	i = 0;
	while (res[i])
	{
		j = 0;
		if (!ft_strncmp(&res[i], keyword, key_len))
		{
			while (j < key_len)
			{
				res[i] = '*';
				j++;
				i++;
			}
		}
		else 
			i++;
	}
	puts(res);
	return (0);
}


int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	filter(av[1]);
	return (0);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

void ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest && dest[i])
		i++;
	while (src && *src)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}
