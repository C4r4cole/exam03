/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:02:29 by fmoulin           #+#    #+#             */
/*   Updated: 2025/09/02 17:25:52 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

int	is_valid(int *solution, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (solution[i] == col)
			return (0);
		if (solution[i] - col == i - row)
			return (0);
		if (col - solution[i] == i - row)
			return (0);
		i++;
	}
	return (1);
}

void	backtracking(int *solution, int row, int size)
{
	int col;
	
	if (row == size)
	{
		print_solution(solution, size);
		return ;
	}
	col = 0;
	while (col < size)
	{
		if (is_valid(solution, row, col))
		{
			solution[row] = col;
			backtracking(solution, row + 1, size);
		}
		col++;
	}
}

int	main(int argc, char **argv)
{
	int	solution[10];
	int size;
	if (argc != 2)
		return (1);

	size = atoi(argv[1]);
	backtracking(solution, 0, size);
	return (0);
}