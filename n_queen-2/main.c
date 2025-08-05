/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:12:25 by fmoulin           #+#    #+#             */
/*   Updated: 2025/08/05 16:05:21 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_queen.h"

int	is_safe(int board[N][N], int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		if (board[i][col] == 1)
			return (0);
		i++;
	}
	i = row - 1;
	j = col - 1;
	while (i >= 0 && j >= 0)
	{
		if (board[i][j] == 1)
			return (0);
		i--;
		j--;
	}
	i = row - 1;
	j = col + 1;
	while (i >= 0)
	{
		if (board[i][j] == 1)
			return (0);
		i--;
		j++;
	}
	return (1);
}

void	print_solution(int board[N][N])
{
	printf("===== Solution =====\n");
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (board[i][j] == 1)
				printf("Q ");
			else
				printf(". ");
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");	
}

void	solve(int board[N][N], int row, int	*solution_count)
{
	int	col;
	
	if (row == N)
	{
		print_solution(board);
		*solution_count += 1;
		return ;
	}
	col = 0;
	while (col < N)
	{
		if (is_safe(board, row, col))
		{
			board[row][col] = 1;
			solve(board, row + 1, solution_count);
			board[row][col] = 0;
		}
		col++;
	}
}

int	main(void)
{
	int board[N][N];
	int row;
	int col;
	int solution_count;
	
	row = 0;
	while (row < N)
	{
		col = 0;
		while (col < N)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
	solution_count = 0;
	solve(board, 0, &solution_count);
	return (0);
}