/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:30:19 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 17:33:45 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static void ft_c_start_queue(t_listlemin *tmp, t_road **start_q, t_road *new_node)
{
    int i;


    i = 0;
    if (!new_node)
    {
        if (!tmp->link)
            exit(write(2, "ERROR\n", 6));
        new_node = ft_create_elem_2();
        *start_q = new_node;
        // new_node->n_r = ft_strdup(tmp->link[i]->name_room);
        // tmp->link[i]->from = ft_strdup(tmp->name_room);
        new_node->n_r = tmp->link[i]->name_room;
        tmp->link[i]->from = tmp->name_room;
        i++;
        while (tmp->link[i])
        {
            new_node->next = ft_create_elem_2();
            new_node = new_node->next;
            // new_node->n_r = ft_strdup(tmp->link[i]->name_room);
            // tmp->link[i]->from = ft_strdup(tmp->name_room);
            new_node->n_r = tmp->link[i]->name_room;
            tmp->link[i]->from = tmp->name_room;
            new_node->next = NULL;
            i++;
        }
    }
}

static void ft_start_queue(t_listlemin *tmp, t_road **start_q, t_road *new_node)
{
    while (tmp)
    {   
        if (tmp->type_room == 1)
        {
            tmp->use = 1;
            ft_c_start_queue(tmp, start_q, new_node);
            break ;
        }
        tmp = tmp->next;
    }
}

static void ft_c_next_queue(t_listlemin *tmp, t_road *start_q, t_road **end_q, t_road *new_node)
{
    int i;

    i = 0;
    while (tmp->link[i])
    {
        while((*end_q)->next)
            *end_q = (*end_q)->next;
        if (tmp->link[i]->use != 1 && ft_cmp_queue(start_q, tmp->link[i]->name_room) == 1)
        {
            new_node = ft_create_elem_2();
            //new_node->n_r = ft_strdup(tmp->link[i]->name_room);
            //tmp->link[i]->from = ft_strdup(tmp->name_room);
            new_node->n_r = tmp->link[i]->name_room;
            tmp->link[i]->from = tmp->name_room;
            (*end_q)->next = new_node;
        }
        i++;
    }
}

static void ft_next_queue(t_listlemin *head, t_listlemin *tmp, t_road *start_q, t_road *new_node)
{
    t_road *end_q;

    end_q = start_q;
    while (tmp)
    {
        if (!start_q)
            exit(write(2, "ERROR\n", 6));
        if (!ft_strcmp(tmp->name_room, start_q->n_r))
        {
            tmp->use = 1;
            ft_c_next_queue(tmp, start_q, &end_q, new_node);
            start_q = start_q->next;
            if (tmp->type_room == 2)
                break ;
            tmp = head;
            continue ;
        }
        tmp = tmp->next;
    }
}

void ft_way(t_listlemin **head)
{
   
    t_listlemin *tmp;
    t_road *new_node;
    t_road *start_q;
    t_road *buff3;
  
    tmp = *head;
    new_node = NULL;
    start_q = NULL;
    
    ft_start_queue(tmp, &start_q, new_node);
    buff3 = start_q;
    // buff3 = start_q;
    ft_next_queue(*head, tmp, start_q, new_node);
    ft_del_2(&buff3);
    // system("leaks -quiet lem-in");
    // exit(1);
}