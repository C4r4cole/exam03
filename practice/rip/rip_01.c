/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip_01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:13:37 by fmoulin           #+#    #+#             */
/*   Updated: 2025/09/03 16:40:21 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_valid(char *str)
{
	int	opened;
	int	closed;
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
	int c;
	int	i;

	if (must_fix == n_fixed && !is_valid(str))
	{
		puts(str);
		return ;
	}
	c = 0;
	i = n;
	while(str[i])
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

int	main(int argc, char **argv)
{
	if(argc != 2)
		return (1);
	int	m_fix;

	m_fix = is_valid(argv[1]);
	rip(argv[1], m_fix, 0, 0);
}