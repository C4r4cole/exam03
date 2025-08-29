/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:08:21 by fmoulin           #+#    #+#             */
/*   Updated: 2025/08/05 19:10:32 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
# define N 5

int	is_safe(char board[N][N], int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		if (board[i][col] == 'Q')
			return (0);
		i++;
	}
	i = row - 1;
	j = col - 1;
	while (i >= 0 && j >= 0)
	{
		if (board[i][j] == 'Q')
			return (0);
		i--;
		j--;
	}
	i = row - 1;
	j = col + 1;
	while (i >= 0 && j < N)
	{
		if (board[i][j] == 'Q')
			return (0);
		i--;
		j++;
	}
	return (1);
}

void	display_solution(char board[N][N])
{
	int	i;
	int	j;

	printf("=== Solution ===\n");
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			printf("%c", board[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
}

void	solve(char board[N][N], int row, int *counter)
{
	int	col;

	col = 0;
	if (row == N)
	{
		display_solution(board);
		*counter += 1;
		return ;
	}
	while (col < N)
	{
		if (is_safe(board, row, col))
		{
			board[row][col] = 'Q';
			solve(board, row + 1, counter);
			board[row][col] = '.';
		}		
		col++;
	}
}

int	main(void)
{
	char	board[N][N];
	int		row;
	int		col;
	int		counter;

	row = 0;
	while (row < N)
	{
		col = 0;
		while (col < N)
		{
			board[row][col] = '.';
			col++;
		}
		row++;
	}
	counter = 0;
	solve(board, 0, &counter);
	printf("Nombre de solutions : [%d]\n", counter);
	return (0);
}
 