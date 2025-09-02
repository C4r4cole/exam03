/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:52:33 by fmoulin           #+#    #+#             */
/*   Updated: 2025/09/02 18:09:14 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_solution(int *solution, int size)
{
	int 	i;
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
		return;
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

int main(void)
{
	int solution[10];
	int	size;
	
	size = 4;
	backtracking(solution, 0, size);
	return (0);
}