/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:31:27 by ale-coss          #+#    #+#             */
/*   Updated: 2025/08/28 12:26:59 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_ret(char **ret);

void print_ret(char **ret)
{
	int i;

	i = -1;
	while (ret && ret[++i])
	{
		if (i)
			printf(" + ");
		printf("%s", ret[i]);
	}
	printf("\n");
}

int is_valid(char *result, char **ret, int r)
{
	while (ret && *ret)
		r += atoi(*(ret++));
	if (r == atoi(result))
		return (1);
	return (0);
}



int powerset(char *result, char **numbers, char **ret, int d)
{
	while (numbers && *numbers && (ret[d] = *numbers) && !(ret[d + 1] = NULL) && !(powerset(result, ++numbers, ret, d + 1)))
		if (is_valid(result, ret, 0))
			print_ret(ret);
	return (ret[d] = NULL, 0);
}

int	main(int ac, char **av)
{
	char **ret;
	
	
	if (ac < 3)
		return (1);
	ret = malloc(sizeof(char *) * (ac));
	*ret = NULL;
	powerset(av[1], &(av[2]), ret, 0);
	free(ret);
}
