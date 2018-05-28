/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:30:19 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/28 15:43:29 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>

int ft_way(t_listlemin **head)
{
   
    t_listlemin *tmp1;
    t_road *new_node;
    t_road *buff;
    t_road *buff2;
    t_road *buff3;
  
    
    tmp1 = *head;
    new_node = 0;
    buff = new_node;
    
    int i;
    int j = 1;

    while (tmp1)
    {   
        if (tmp1->type_room == 1)
        {
            tmp1->use = 1;
            i = 0;
            if (!new_node)
            {
                new_node = (t_road*)malloc(sizeof(t_road));
                buff = new_node;
                new_node->n_r = ft_strdup(tmp1->link[i]->name_room);
                tmp1->link[i]->step = j;
                i++;
                while (tmp1->link[i])
                {
                    new_node->next = (t_road*)malloc(sizeof(t_road));
                    new_node = new_node->next;
                    new_node->n_r = ft_strdup(tmp1->link[i]->name_room);
                    tmp1->link[i]->step = j;
                    new_node->next = 0;
                    i++;
                }
            }
            break ;
        }
        tmp1 = tmp1->next;
    }
    
    tmp1 = *head;
    buff3 = buff;
    buff2 = buff;
    
        while (tmp1)
        {
            if (!ft_strcmp(tmp1->name_room, buff->n_r))
            {
                tmp1->use = 1;
                i = 0;
                while (tmp1->link[i])
                {
                            
                    while(buff2->next)
                    {
                       buff2 = buff2->next;
                       buff2->next = NULL;
                    }
                    if (tmp1->link[i]->use != 1)
                    {
                        j++; // Проверить j!!!
                        new_node = (t_road*)malloc(sizeof(t_road));
                        new_node->n_r = ft_strdup(tmp1->link[i]->name_room);
                        buff2->next = new_node;
                        tmp1->link[i]->step = j;
                    }
                    i++;
                }
                printf("%d-%d\n", tmp1->use, tmp1->step);
                if (tmp1->type_room == 2)
                    break ;
                buff = buff->next;
                tmp1 = *head;
                continue ;
            }
            tmp1 = tmp1->next;
        }
    
    while (buff3)
    {
        printf("%s", buff3->n_r);
        buff3 = buff3->next;
    }
    
    return (0);
}