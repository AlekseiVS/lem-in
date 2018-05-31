/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 09:57:37 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/31 16:59:26 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>

static t_road *ft_find_finish(t_road *buff)
{
    while (buff)
    {
        if (buff->next == NULL)
            return (buff);
        buff = buff->next;
    }
    return (0);
}

static void ft_arry_ant(t_road *road, t_ant **ant_arry, int ant)
{
    t_ant ant_s;
    int i;
    int j;

    *ant_arry = (t_ant*)malloc(sizeof(t_ant) * ant);
    i = 0;
    j = 1;
    while (i < ant)
    {
        ant_s.path = road;
        ant_s.name_ant = j++;
        ant_s.fin = 0;
        (*ant_arry)[i] = ant_s;
        i++;
    }

}

void ft_ant_way(t_road *road, int ant)
{
    t_ant *ant_arry;
    t_road *end;
    int i;
    int print;

    ft_arry_ant(road, &ant_arry, ant);
    end = ft_find_finish(road);
    while (1)
    {
        i = 0;
        print = 0;
        while (i < ant)
        {
            if (ant_arry[i].path->next != NULL && ant_arry[i].path->next->tg == 0)
            {
                if (print == 1)
                    printf(" ");
                ant_arry[i].path->next->tg = 1;
                ant_arry[i].path->tg = 0;
                ant_arry[i].path = ant_arry[i].path->next;
                printf("L%d-%s", ant_arry[i].name_ant, ant_arry[i].path->n_r);
                print = 1;
                //Проверить работу с минусовой координатой!!!!!!!
            }
            else if (ant_arry[i].path->next == NULL && !ant_arry[i].fin)
            {
                end->ant_room++;
                ant_arry[i].fin++;
                ant_arry[i].path->tg = 0;
            }   
            i++;
        }
        printf("\n");
        if (end->ant_room == ant)
            break ;
    }
}