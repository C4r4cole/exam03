/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:50:22 by fmoulin           #+#    #+#             */
/*   Updated: 2025/08/06 17:13:11 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	clean_board(int **board, int n)
{
	int	i;
	
	i = 0;
	while (i < n)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

int	**create_board(int n)
{
	int	row;
	int **board;
	
	board = malloc(sizeof(int *) * n);
	if (!board)
		return (NULL);
	row = 0;
	while (row < n)
	{
		board[row] = malloc(sizeof(int) * n);
		row++;
	}
	return (board);	
}

void	board_init(int **board, int	n)
{
	int	i;
	int j;
		
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	is_safe(int **board, int row, int col)
{
	int i;
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
	while (i >= 0 && j >= 0)
	{
		if (board[i][j] == 1)
			return (0);
		i--;
		j++;
	}
	return (1);
}

void	display_solution(int **board, int n)
{
	int	*tab;
	int i;
	int j;
	
	tab = malloc(sizeof(int) * n);
	if (!tab)
		return ;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (board[i][j] == 1)
			{
				tab[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	free(tab);
}

void	solve(int **board, int row, int n)
{
	int	col;
	
	if (row == n)
	{
		display_solution(board, n);
		return ;
	}
	col = 0;
	while (col < n)
	{
		if (is_safe(board, row, col))
		{
			board[row][col] = 1;
			solve(board, row + 1, n);
			board[row][col] = 0;
		}
		col++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	n;
		int	**board;

		n = atoi(argv[1]);
		board = create_board(n);
		board_init(board, n);
		solve(board, 0, n);
		clean_board(board, n);
	}
	else
	{
		printf("\n");
	}
	return (0);
}
