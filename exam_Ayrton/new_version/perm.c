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
#include <string.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int is_c_not_already_in_result(char c, char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_bubble_sort(char *s, int size)
{
	int	nb_passage;
	char	temp;
	int	i;

	nb_passage = 0;
	temp = 0;
	while (nb_passage != size)
	{		
		i = 0;
		while (i < size - 1)
		{
			if (s[i] > s[i + 1])
			{
				temp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = temp;
			}
			i++;
		}
		nb_passage++;
	}
}

void printcombn(char *str, char *result, int size, int i)
{
	char *str1;
	int	j;

	ft_bubble_sort(str, size);
	str1 = str;
	j = 0;
	while (str1[j])
	{
		if (is_c_not_already_in_result(str1[j], result))
		{
			result[i] = str1[j];
			result[i+1] = '\0';
			if (i + 1 == size)
				puts(result);
			else
				printcombn(str, result, size, i + 1);
			result[i] = '\0';
		}
		j++;
	}
	
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	char *result = malloc(sizeof(char) * (ft_strlen(av[1]) + 1));
	result[0] = '\0';
	printcombn(av[1], result, ft_strlen(av[1]), 0);
	free(result);
	return (0);
}

