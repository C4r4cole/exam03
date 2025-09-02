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
#include <stdlib.h>

void print_res(char **set)
{
	int i = 0;

	while (set[i])
	{
		if (i > 0)
			printf(" ");
		printf("%s", set[i]);
		i++;
	}
	printf("\n");
}

int is_valid(char *target, char **set)
{
	int sum = 0;
	int i = 0;

	while (set[i])
	{
		sum = sum + atoi(set[i]);
		i++;
	}
	return (sum == atoi(target));
}

void powerset(char *target, char **numbers, int numbers_len, char **set, int depth, int index)
{
	if (index == numbers_len)
	{
		set[depth] = NULL; // NULL-terminate à chaque fin de branche
		if (is_valid(target, set))
			print_res(set);
		return;
	}
	// Inclure numbers[index]
	set[depth] = numbers[index];
	powerset(target, numbers, numbers_len, set, depth + 1, index + 1);
	// Ne pas inclure numbers[index]
	powerset(target, numbers, numbers_len, set, depth, index + 1);
}

int main(int ac, char **av)
{
	if (ac < 3)
		return (1);

	int numbers_len = ac - 2;
	char **set = malloc(sizeof(char *) * (numbers_len + 1)); // +1 pour le NULL
	if (!set)
		return (1);

	set[0] = NULL; // initial NULL
	powerset(av[1], av + 2, numbers_len, set, 0, 0);
	free(set);
	return (0);
}
