/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:36:13 by gaeudes           #+#    #+#             */
/*   Updated: 2025/08/26 17:57:33 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

void	rec_ncomp(int depth, int depth_max, char *nb, char start)
{
	if (depth == depth_max)
	{
		write(1, nb, depth_max);
		write(1, "\n", 1);
		return ;
	}
	nb[depth] = start;
	while (nb[depth] <= '9')
	{
		rec_ncomp(depth + 1, depth_max, nb, nb[depth] + 1);
		nb[depth]++;
	}
}

void	ncomp(int n)
{
	char	nb[10];

	rec_ncomp(0, n, nb, '0');
}

int	is_valid(int depth, char *board)
{
	const char	my_char = board[depth];
	int	i = 0;

	while (i < depth)
	{
		if (board[i] == my_char)
			return (0);
		else if (depth - i == my_char - board[i])
			return (0);
		else if (i - depth == my_char - board[i])
			return (0);
		++i;
	}
	return (1);
}


int	rec_nqueen(int depth, int depth_max, char *board)
{
	int	count = 0;

	if (depth == depth_max)
	{
		write(1, board, depth_max);
		write(1, "\n", 1);
		return (1);
	}
	board[depth] ='0';
	while (board[depth] <= '0' + depth_max - 1)
	{
		if (is_valid(depth, board))
			count += rec_nqueen(depth + 1, depth_max, board);
		board[depth]++;
	}
	return (count);
}

int	nqueen(int n)
{
	char board[100];

	if (n <= 12 && n >=1)
		return (rec_nqueen(0, n, board));
	return (0);
}

int ft_strlen(char *str)
{
	char *start = str;

	while (*str)
		++str;
	return (str - start);
}

int	ft_strcmp(char *s1, char *s2, int n)
{
	for (int i = 0; i < n; ++i)
		if (s1[i] != s2[i])
			return (s2[i] - s1[i]);
	return (0);
}

void	bbsort(char **sstr, int str_len, int size)
{
	char *tmp;
	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j < size; ++j)
		{
			if (ft_strcmp(sstr[i], sstr[j], str_len) < 0)
			{
				tmp = sstr[i];
				sstr[i] = sstr[j];
				sstr[j] = tmp;
				i = -1;
				break;
			}
		}
	}
}

char	**tabperm(int len, int *ttsize)
{
	*ttsize = 1;
	for (int i = 1; i <= len; ++i)
		*ttsize *= i;

	char **tab_perm = malloc(sizeof(char *) * *ttsize);
	for (int i = 0; i < *ttsize; ++i)
		tab_perm[i] = malloc(len);
	return (tab_perm);
}

void	swap(char *a, char *b)
{
	char c = *a;
	*a = *b;
	*b = c;
}

void	memecpy(char *dst, char *src, int l)
{
	for (int i = 0; i < l; ++i)
		dst[i] = src[i];
}

void	rec_perm(int depth, int max_depth, char *str, char **tab)
{
	static int itab = 0;

	if (depth == 0)
		itab = 0;
	if (depth == max_depth)
	{
		memecpy(tab[itab], str, max_depth);
		++itab;
		return ;
	}
	for (int i = depth; i < max_depth; ++i)
	{
		swap(&str[depth], &str[i]);
		rec_perm(depth + 1, max_depth, str, tab);
		swap(&str[depth], &str[i]);
	}
}



void	perm(char *str)
{
	int len = ft_strlen(str);
	int		ttsize;
	char	**tab_perm = tabperm(len, &ttsize);

	rec_perm(0, len, str, tab_perm);
	bbsort(tab_perm, len, ttsize);
	for (int i = 0; i < ttsize; ++i)
	{
		write(1, tab_perm[i], len);
		write(1, "\n", 1);
		free(tab_perm[i]);
	}
	free(tab_perm);
}

int main(void)
{
	char str[] = "15348";

	perm(str);
}
