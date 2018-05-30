/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:56:08 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/30 12:54:36 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>

int ft_ant(char *line, int *ant)
{
    if(*line && line[0] == '#' && !(ft_strcmp(line, "##start") == 0) && !(ft_strcmp(line, "##end") == 0))
    {
        printf("%s\n", line);
        return (1);
    }
    //Добавить проверку на комментарий!!!
    if (*ant == 0)
    {
        int i = 0;
        while(ft_isdigit(line[i]) == 1)
            i++;
        if (line[i] != '\0')
            exit(printf("ERROR\n"));
        *ant = ft_atoi(line);
        ft_putnbr(*ant);
        write(1, "\n", 1);
        return (1);
    }
    return (0);
}
