/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip_00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:59:26 by fmoulin           #+#    #+#             */
/*   Updated: 2025/09/03 16:12:29 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_val(char *str)
{
    int opened = 0, closed = 0;

    for (int i = 0; str[i]; i++)
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
    }
    return opened + closed;
}

void    rip(char *str, int must_fic, int n_fix, int pos)
{
    if (must_fic == n_fix && !is_val(str))
    {
        puts(str);
        return;
    }
    for(int i = pos; str[i]; i++)
    {
        if (str[i] == '('  || str[i] == ')')
        {
            int c = str[i];
            str[i] = ' ';
            rip(str, must_fic, n_fix + 1, i);
            str[i] = c;
        }
    }
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
    int m_fix = is_val(argv[1]);
    rip(argv[1], m_fix, 0, 0);
}