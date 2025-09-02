/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:44:47 by                   #+#    #+#             */
/*   Updated: 2025/09/02 17:52:49 by 		          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	is_valid(char *str);

int	rip(char *str, char *str0, int lvl, int depth_max)
{
	int			i;
	char		temp;
	static int	is_res;

	if (lvl == 1 && is_valid(str0))
		return (puts(str0), 1);
	i = -1;
	while (str && str[++i])
	{
		temp = str[i];
		str[i] = ' ';
		if (is_valid(str0))
		{
			puts(str0);
			is_res = 1;
		}
		if (lvl < depth_max)
			rip(&str[i], str0, lvl + 1, depth_max);
		str[i] = temp;
	}
	if (lvl == 1 && !is_res && str0[depth_max])
		return (rip(str0, str0, 1, depth_max + 1));
	return (is_res);
}

static int	is_valid(char *str)
{
	int	flag;
	int	filled;

	filled = 0;
	flag = 0;
	while (str && *str)
	{
		if (*str == '(')
		{
			filled = 1;
			flag++;
		}
		else if (*str == ')')
			flag--;
		if (flag < 0)
			return (0);
		str++;
	}
	if (flag || !filled)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	return (!rip(av[1], av[1], 1, 1));
}
