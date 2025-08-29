/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:10:04 by ale-coss          #+#    #+#             */
/*   Updated: 2025/08/28 12:26:17 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_c_not_already_in_result(char c, char *str)
{
	while (str && *str)
	{
		if (*str == c)
			return (0);
		str++;
	}
	return (1);
}

void printcombn(const char *str, char *result, int i)
{
	char *str1;

	str1 = (char *)str;
	while (*str1)
	{
		if (is_c_not_already_in_result(*str1, result))
		{
			result[i] = *str1;
			result[i+1] = 0;
			if (i + 1 == strlen(str))
				puts(result);
			else
				printcombn(str, result, i + 1);
			result[i]=0;
		}
		str1++;
	}
	
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	char *result = malloc(sizeof(char) * (1 + strlen(av[1])));
	*result = 0;
	printcombn(av[1], result, 0);
	free(result);
	return (0);
}
