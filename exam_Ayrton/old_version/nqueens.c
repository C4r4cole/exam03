/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:50:00 by user              #+#    #+#             */
/*   Updated: 2025/08/25 17:02:33 by ale-coss         ###   ########.fr       */
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

int		main(void)
{
	int	solution[10];
	int	size;

	size = 4; /* Essaie avec 4 ou 8 pour le vrai problème */
	backtrack(solution, 0, size);
	return (0);
}

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
