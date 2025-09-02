/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template_backtracking.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:34:56 by user              #+#    #+#             */
/*   Updated: 2025/08/25 16:13:32 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Exemple de fonction utilitaire pour afficher une solution
** (à adapter selon l'exercice).
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
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

/*
** Vérifie si l'élément courant peut être placé
** (la condition dépend du problème : conflit, déjà utilisé, etc.).
*/
int		is_valid(int *solution, int pos, int candidate)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (solution[i] == candidate)
			return (0);
		/* Exemple : ajouter d'autres conditions ici */
		i++;
	}
	return (1);
}

/*
** Fonction récursive de backtracking
** pos : position actuelle dans la solution
** size : taille totale du problème (n)
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

/*
** Exemple d'utilisation dans le main
*/
int		main(void)
{
	int	solution[10];
	int	size;

	size = 4; /* exemple pour N-Queens ou permutations avec n = 4 */
	backtrack(solution, 0, size);
	return (0);
}
