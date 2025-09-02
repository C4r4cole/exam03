/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcombn_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:38:24 by fmoulin           #+#    #+#             */
/*   Updated: 2025/09/02 21:48:00 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_c_neither_in_result_nor_inferior(char c, char *result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		if (c <= result[i])
			return (0);
		i++;
	}
	return (1);
}

void	printcombn(char *result, int nb, int n)
{
	char	nbr;

	nbr = '0';
	while (nb && nbr < '9')
	{
		if (is_c_neither_in_result_nor_inferior(nbr, result))
		{
			result[n] = nbr;
			result[n + 1] = '\0';
			if (n + 1 == nb)
				puts(result);
			else
				printcombn(result, nb, n + 1);
			result[n] = '\0';
		}
		nbr++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int		nb;
	char	*result;

	nb = atoi(argv[1]);
	result = malloc(sizeof(char) * (nb + 1));
	if (!result)
		return (1);
	result[0] = '\0';
	printcombn(result, nb, 0);
	free(result);
	return (0);
}