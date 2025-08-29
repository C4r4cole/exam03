/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens_puzzle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:48:20 by ale-coss          #+#    #+#             */
/*   Updated: 2025/08/28 12:25:53 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define NQ 8

void	branching(char *tab, int a, int *count, int nq);
int		is_checked(char *tab, int a, int i);

int	ft_n_queens_puzzle(int nq)
{
	char	tab[1024];
	int		count;

	count = 0;
	branching(tab, 0, &count, nq);
	return (count);
}

void	branching(char *tab, int a, int *count, int nq)
{
	tab[a] = '0' - 1;
	tab[a + 1] = 0;
	while (++tab[a] < '0' + nq)
	{
		if (is_checked(tab, a, -1) == 1)
		{
			if (a == nq - 1)
			{
				// puts(tab);
				write(1, tab, nq);
				write(1, "\n", 1);
				*count = *count + 1;
			}
			else
				branching(tab, a + 1, count, nq);
		}
	}
}

int	is_checked(char *tab, int a, int i)
{
	while (++i < a)
		if (tab[a] == tab[i] || (tab[i] - tab[a] == a - i)
			|| (tab[a] - tab[i] == a - i))
			return (0);
	return (1);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	n_of_sol;

	if (ac != 2)
		return(printf("Wrong number of arguments\n"), 1);

	n_of_sol = ft_n_queens_puzzle(atoi(av[1]));
	printf("\n\n%d\n", n_of_sol);
	(void) n_of_sol;
	return (0);
}
