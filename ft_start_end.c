/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:55:18 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/29 17:00:01 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>

int ft_start_end(char *line, int *type)
{
    if(line[0] == '#')
    {
        if (ft_strcmp(line, "##start") == 0)
        {
            *type = 1;
            printf("%s\n", line);
        }
        else if (ft_strcmp(line, "##end") == 0)
        {
            *type = 2;
            printf("%s\n", line);
        }
        else
            printf("%s\n", line);
        return (1);
    }
    return (0);
}