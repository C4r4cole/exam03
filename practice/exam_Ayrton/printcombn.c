/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcombn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:10:04 by ale-coss          #+#    #+#             */
/*   Updated: 2025/08/28 12:27:27 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_c_neither_in_result_nor_inferior(char c, char *str)
{
	while (str && *str)
	{
		if (*str >= c)
			return (0);
		str++;
	}
	return (1);
}

void printcombn(char *result, int i, int n)
{
	char num;
	
	num = '0' - 1;
	while (n && ++num <= '9')
	{
		
		if (is_c_neither_in_result_nor_inferior(num, result))
		{
			result[i] = num;
			result[i+1] = 0;
			if (i + 1 == n)
				puts(result);
			else
				printcombn(result, i + 1, n);
			result[i]=0;
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int n = atoi(av[1]);
	char *result = malloc(sizeof(char) * (1 + n));
	*result = 0;
	printcombn(result, 0, n);
	free(result);
	return (0);
}
