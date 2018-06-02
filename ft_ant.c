/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:56:08 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 15:41:04 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_ant(char *line, int *ant)
{
    if(*line && line[0] == '#' && !(ft_strcmp(line, "##start") == 0) && !(ft_strcmp(line, "##end") == 0))
    {
        ft_putstr(line);
        write(1, "\n", 1);
        return (1);
    }
    if (*ant == 0)
    {
        int i = 0;
        while(ft_isdigit(line[i]) == 1)
            i++;
        if (line[i] != '\0' || ft_strlen(line) > 6)
            exit(write(2, "ERROR\n", 6));
        *ant = ft_atoi(line);
        if (*ant <= 0)
            exit(write(2, "ERROR\n", 6));
        ft_putnbr(*ant);
        write(1, "\n", 1);
        return (1);
    }
    return (0);
}
