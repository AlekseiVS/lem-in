/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:30:19 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/31 13:30:38 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>

static void ft_c_start_queue(t_listlemin *tmp, t_road **buff, t_road *new_node)
{
    int i;

    i = 0;
    if (!new_node)
    {
        new_node = ft_create_elem_2();
        *buff = new_node;
        new_node->n_r = ft_strdup(tmp->link[i]->name_room);
        tmp->link[i]->from = ft_strdup(tmp->name_room);
        i++;
        while (tmp->link[i])
        {
            new_node->next = ft_create_elem_2();
            new_node = new_node->next;
            new_node->n_r = ft_strdup(tmp->link[i]->name_room);
            tmp->link[i]->from = ft_strdup(tmp->name_room);
            new_node->next = NULL;
            i++;
        }
    }
}

static void ft_start_queue(t_listlemin *tmp, t_road **buff, t_road *new_node)
{
    while (tmp)
    {   
        if (tmp->type_room == 1)
        {
            tmp->use = 1;
            ft_c_start_queue(tmp, buff, new_node);
            break ;
        }
        tmp = tmp->next;
    }
}

static void ft_c_next_queue(t_listlemin *tmp, t_road *buff, t_road **buff2, t_road *new_node)
{
    int i;

    i = 0;
    while (tmp->link[i])
    {
        while((*buff2)->next)
            *buff2 = (*buff2)->next;
        if (tmp->link[i]->use != 1 && ft_cmp_queue(buff, tmp->link[i]->name_room) == 1)
        {
            new_node = ft_create_elem_2();
            new_node->n_r = ft_strdup(tmp->link[i]->name_room);
            tmp->link[i]->from = ft_strdup(tmp->name_room);
            (*buff2)->next = new_node;
        }
        i++;
    }
}

static void ft_next_queue(t_listlemin *head, t_listlemin *tmp, t_road *buff, t_road *new_node)
{
    t_road *buff2;

    buff2 = buff;
    while (tmp)
    {
        if (!ft_strcmp(tmp->name_room, (buff)->n_r))
        {
            tmp->use = 1;
            ft_c_next_queue(tmp, buff, &buff2, new_node);
            buff = (buff)->next;
            if (tmp->type_room == 2)
                break ;
            tmp = head;
            continue ;
        }
        tmp = tmp->next;
    }
}

int ft_way(t_listlemin **head)
{
   
    t_listlemin *tmp;
    t_road *new_node;
    t_road *buff;
    t_road *buff3;
  
    tmp = *head;
    new_node = NULL;
    buff = NULL;
    
    ft_start_queue(tmp, &buff, new_node);
    buff3 = buff;
    ft_next_queue(*head, tmp, buff, new_node);
   
    // printf("queue: ");
    // while (buff3)
    // {
    //     printf("%s", buff3->n_r);
    //     buff3 = buff3->next;
    // }
    // printf("\n");
    return (0);
}