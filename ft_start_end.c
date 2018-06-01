/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:55:18 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/01 15:28:33 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>

int ft_start_end(char *line, int *type, int *tg_s, int *tg_e)
{
    if(line[0] == '#')
    {
        if (ft_strcmp(line, "##start") == 0)
        {
            if (*tg_s == 1)
                exit(printf("ERROR\n"));
            *tg_s = 1;
            *type = 1;
            printf("%s\n", line);
        }
        else if (ft_strcmp(line, "##end") == 0)
        {
            if (*tg_e == 1)
                exit(printf("ERROR\n"));
            *tg_e = 1;
            *type = 2;
            printf("%s\n", line);
        }
        else
            printf("%s\n", line);
        return (1);
    }
    return (0);
}