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

int is_c_neither_in_result_nor_inferior(char c, char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= c)
			return (0);
		i++;
	}
	return (1);
}

void printcombn(char *result, int nb, int i)
{
	char num;
	
	num = '0';
	while (nb && num <= '9')
	{
		
		if (is_c_neither_in_result_nor_inferior(num, result))
		{
			result[i] = num;
			result[i + 1] = '\0';
			if (i + 1 == nb)
				puts(result);
			else
				printcombn(result, nb, i + 1);
			result[i] = '\0';
		}
		num++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int nb = atoi(av[1]);
	char *result = malloc(sizeof(char) * (nb + 1));
	result[0] = '\0';
	printcombn(result, nb, 0);
	free(result);
	return (0);
}
