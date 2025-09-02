/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:26:22 by fmoulin           #+#    #+#             */
/*   Updated: 2025/09/02 20:33:55 by fmoulin          ###   ########.fr       */
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

int	is_c_not_already_in_result(char c, char *result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		if (result[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_bubble_sort(char *s, int size)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (s[j] > s[j + 1])
			{
				tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	printcombn(char *str, char *result, int size, int n)
{
	char	*str1;
	int		i;

	ft_bubble_sort(str, size);
	str1 = str;
	i = 0;
	while (str1[i])
	{
		if (is_c_not_already_in_result(str1[i], result))
		{
			result[n] = str1[i];
			result[n + 1] = '\0';
			if (n + 1 == size)
				puts(result);
			else
				printcombn(str, result, size, n + 1);
			result[n] = '\0';
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	char	*result;

	result = malloc(sizeof(char) * (ft_strlen(argv[1]) + 1));
	if (!result)
		return (0);
	result[0] = '\0';
	printcombn(argv[1], result, ft_strlen(argv[1]), 0);
	free(result);
	return (0);
}