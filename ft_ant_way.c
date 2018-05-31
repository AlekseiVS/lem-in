/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 09:57:37 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/31 11:42:26 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>

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
        (*ant_arry)[i] = ant_s;
        i++;
    }

}


void ft_ant_way(t_road *road, int ant)
{
    t_ant *ant_arry;

    ft_arry_ant(road, &ant_arry, ant);

    int i = 0;
    while (i < ant)
    {
        printf("%d", ant_arry[i].name_ant);
        i++;
    }
    printf("\n");

    
    printf("ant: %d\n", ant);
    printf("road: ");
    while (road)
    {
        printf("%s", road->n_r);
        road = road->next;
    }
}