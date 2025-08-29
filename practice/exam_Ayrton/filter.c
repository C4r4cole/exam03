/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:42:57 by ale-coss          #+#    #+#             */
/*   Updated: 2025/08/28 16:15:36 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str);
int ft_strncmp(char *str1, char *str2, int n);
void ft_strcat(char *dest, char *src);

int filter(char *keyword)
{
	char ret[1048575];
	char buffer[100000];
	int n;
	char *src;
	
	ret[0] = 0; //met un /0 dedans;
	while (1)
	{
		n = read(0, &buffer, rand() % 10);
		if (n == -1)
			return (0);
		if (n == 0)
			break ;
		buffer[n] = 0; //fini la string
		ft_strcat(ret, buffer);
	}
	src = ret;
	while (src && *src)
	{
		n = 0;
		if (!ft_strncmp(src, keyword, ft_strlen(keyword)))
			while (n++ < ft_strlen(keyword))
				*src++ = '*';
		else 
			src++;
	}
	puts(ret);
	return (1);
}


int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	// printf("%i\n", ft_strncmp(av[1], "laila", 5));
	filter(av[1]);
	return (0);
}

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str && *str++)
		len++;
	return (len);
}

int ft_strncmp(char *str1, char *str2, int n)
{
	int i;
	
	if (!str1 || !str2)
		return (1);
	i = -1;
	while (n && str1[++i] && str2[i] && str1[i] == str2[i])
		n--;	
	return (str1[i] - str2[i]);
}

void ft_strcat(char *dest, char *src)
{
	while (dest && *dest)
		dest++;
	while (src && *src)
		*dest++ = *src++;
	*dest = 0;
}
