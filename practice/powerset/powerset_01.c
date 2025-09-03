/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:44:18 by fmoulin           #+#    #+#             */
/*   Updated: 2025/09/03 13:03:34 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_res(char **set)
{
	int	i;
	
	i = 0;
	while (set[i])
	{
		if (i > 0)
			printf(" ");
		printf("%s", set[i]);
		i++;
	}
	printf("\n");
}

int	is_valid(char *target, char **set)
{
	int	i;
	int	sum;
	
	i = 0;
	sum = 0;
	while (set[i])
	{
		sum = sum + atoi(set[i]);
		i++;
	}
	return (sum == atoi(target)) ;
}

void powerset(char *target, char **numbers, int nbr_len, char **set, int depth, int index)
{
	if (index == nbr_len)
	{
		set[depth] = NULL;
		if (is_valid(target, set))
			print_res(set);
		return ;
	}
	set[depth] = numbers[index];
	powerset(target, numbers, nbr_len, set, depth + 1, index + 1);
	powerset(target, numbers, nbr_len, set, depth, index + 1);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	
	int	nbr_len;
	char **set;
	
	nbr_len = argc - 2;
	set = malloc(sizeof(char *) * (nbr_len + 1));
	if (!set)
		return (1);
	set[0] = NULL;
	powerset(argv[1], argv + 2, nbr_len, set, 0, 0);
	free(set);
}