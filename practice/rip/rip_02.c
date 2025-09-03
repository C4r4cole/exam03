/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip_02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:43:24 by fmoulin           #+#    #+#             */
/*   Updated: 2025/09/03 16:58:01 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	how_many_parenthesis(char *str)
{
	int	opened;
	int closed;
	int	i;

	opened = 0;
	closed = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '(')
			opened++;
		else if (str[i] == ')')
		{
			if (opened > 0)
				opened--;
			else
				closed++;
		}
		i++;
	}
	return (opened + closed);
}

void	rip(char *str, int must_fix, int n_fixed, int n)
{
	int	i;
	int	c;
	
	if (must_fix == n_fixed && !how_many_parenthesis(str))
	{
		puts(str);
		return ;
	}
	i = n;
	c = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == ')')
		{
			c = str[i];
			str[i] = ' ';
			rip(str, must_fix, n_fixed + 1, n);
			str[i] = c;	
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int	must_fix;
	
	if (argc != 2)
		return (1);
	must_fix = how_many_parenthesis(argv[1]);
	rip(argv[1], must_fix, 0, 0);
}