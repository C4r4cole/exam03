/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:18:41 by ale-coss          #+#    #+#             */
/*   Updated: 2025/08/28 14:29:53 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>

int    ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

int    contain(char *res, char *filter)
{
    int i = 0;
    int j = 0;
    if (!filter[0])
        return -1;
    while(res[i])
    {
        j = 0;
        while (res[i + j] && filter[j] && res[i + j] == filter[j])
            j++;
        if (!filter[j])
            return i;
        i++;
    }
    return -1;
}

void    filter(char *res, char *filter)
{
    int pos;
    int filtersize = ft_strlen(filter);
    int i;
    if (filtersize == 0)
        return ;
    while ((pos = contain(res, filter)) != -1)
    {
        i = 0;
        while (i < filtersize && res[i + pos])
        {
            res[i + pos] = '*';
            i++;
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    char res[1000000];
    char bf[1000000];
    int cursor = 0;
    int bytes_read = read(0, bf, sizeof(bf));
    int i;
    while(bytes_read > 0)
    {
        i = -1;
        while (++i < bytes_read)
            res[i + cursor] = bf[i];
        cursor += bytes_read;
        bytes_read = read(0, bf, sizeof(bf));
    }
    res[cursor] = 0;
    filter(res, av[1]);
    printf("%s", res);
}
