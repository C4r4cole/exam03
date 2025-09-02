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

#include <unistd.h>

/*
** Affiche une solution sous forme de positions
** Exemple : "1 3 0 2" pour N = 4
*/
void	print_solution(int *solution, int size)
{
	int		i;
	char	c;

	i = 0;
	while (i < size)
	{
		c = solution[i] + '0';
		write(1, &c, 1);
		if (i < size - 1)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

/*
** Vérifie si on peut placer une reine en (pos, candidate).
** - pas deux reines dans la même colonne
** - pas deux reines sur une diagonale
*/
int		is_valid(int *solution, int pos, int candidate)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (solution[i] == candidate)
			return (0);
		if ((solution[i] - candidate) == (i - pos))
			return (0);
		if ((candidate - solution[i]) == (i - pos))
			return (0);
		i++;
	}
	return (1);
}

/*
** Backtracking : solution[pos] = colonne de la reine dans la ligne pos
*/
void	backtrack(int *solution, int pos, int size)
{
	int	candidate;

	if (pos == size)
	{
		print_solution(solution, size);
		return ;
	}
	candidate = 0;
	while (candidate < size)
	{
		if (is_valid(solution, pos, candidate))
		{
			solution[pos] = candidate;
			backtrack(solution, pos + 1, size);
		}
		candidate++;
	}
}

int		main(int ac, char **av)
{
	int	solution[1000];
	int	size;

	size = atoi(av[1]); /* Essaie avec 4 ou 8 pour le vrai problème */
	backtrack(solution, 0, size);
	return (0);
}

// solution = tableau qui représente la solution partielle ou complète.
// solution[i] = colonne de la reine sur la ligne i.
// pos = ligne actuelle dans laquelle on essaie de placer une reine.
// candidate = colonne qu’on teste pour placer la reine dans la ligne pos.
// si is_valid(solution, pos, candidate) renvoie vrai, on peut placer la reine à solution[pos] = candidate.
















// void	print_solution(int *solution, int size)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (solution[i] == j)
// 				write(1, "Q", 1);
// 			else
// 				write(1, ".", 1);
// 			j++;
// 		}
// 		write(1, "\n", 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// }


