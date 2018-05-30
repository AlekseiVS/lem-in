/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:30:19 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/30 11:24:23 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>

int ft_queue(t_road *buff, char *name_room)
{
    while (buff)
    {
        if (!ft_strcmp(name_room, buff->n_r))
            return (0);
        buff = buff->next;
    }
    return (1);
}

static void ft_start_queue(t_listlemin *tmp1, t_road **buff, t_road *new_node)
{
    int i;
    
    while (tmp1)
    {   
        if (tmp1->type_room == 1)
        {
            tmp1->use = 1;
            i = 0;
            if (!new_node)
            {
                new_node = ft_create_elem_2();
                *buff = new_node;
                new_node->n_r = ft_strdup(tmp1->link[i]->name_room);
                tmp1->link[i]->from = ft_strdup(tmp1->name_room);
                i++;
                while (tmp1->link[i])
                {
                    new_node->next = ft_create_elem_2(); //(t_road*)malloc(sizeof(t_road));
                    new_node = new_node->next;
                    new_node->n_r = ft_strdup(tmp1->link[i]->name_room);
                    tmp1->link[i]->from = ft_strdup(tmp1->name_room);
                    new_node->next = NULL;
                    i++;
                }
            }
            break ;
        }
        tmp1 = tmp1->next;
    }
}

static void ft_next_queue(t_listlemin **head, t_listlemin *tmp1, t_road *buff, t_road *new_node)
{
    int i;
    t_road *buff2;

    buff2 = buff;
    while (tmp1)
    {
        if (!ft_strcmp(tmp1->name_room, (buff)->n_r))
        {
            tmp1->use = 1;
            i = 0; 
            while (tmp1->link[i])
            {
                while(buff2->next)
                {
                    buff2 = buff2->next;
                }
                if (tmp1->link[i]->use != 1 && ft_queue(buff, tmp1->link[i]->name_room) == 1)
                {
                    // j++;
                    new_node = (t_road*)malloc(sizeof(t_road));
                    new_node->next = NULL;
                    new_node->n_r = ft_strdup(tmp1->link[i]->name_room);
                    tmp1->link[i]->from = ft_strdup(tmp1->name_room);
                    buff2->next = new_node;
                    // tmp1->link[i]->step = j;
                }
                i++;
            }
            buff = (buff)->next;
            if (tmp1->type_room == 2)
                break ;
            tmp1 = *head;
            continue ;
        }
        tmp1 = tmp1->next;
    }
}

int ft_way(t_listlemin **head)
{
   
    t_listlemin *tmp1;
    t_road *new_node;
    t_road *buff;
    // t_road *buff2;
    t_road *buff3;
  
    
    tmp1 = *head;
    new_node = 0;
    buff = new_node;
    
    // int i;
    // int j = 1;

    ft_start_queue(tmp1, &buff, new_node);
    // while (tmp1)
    // {   
    //     if (tmp1->type_room == 1)
    //     {
    //         tmp1->use = 1;
    //         i = 0;
    //         if (!new_node)
    //         {
    //             new_node = (t_road*)malloc(sizeof(t_road));
    //             new_node->next = NULL;
    //             buff = new_node;
    //             new_node->n_r = ft_strdup(tmp1->link[i]->name_room);
    //             tmp1->link[i]->from = ft_strdup(tmp1->name_room);
    //             tmp1->link[i]->step = j;
    //             i++;
    //             while (tmp1->link[i])
    //             {
    //                 new_node->next = (t_road*)malloc(sizeof(t_road));
    //                 new_node = new_node->next;
    //                 new_node->n_r = ft_strdup(tmp1->link[i]->name_room);
    //                 tmp1->link[i]->from = ft_strdup(tmp1->name_room);
    //                 tmp1->link[i]->step = j;
    //                 new_node->next = NULL;
    //                 i++;
    //             }
    //         }
    //         break ;
    //     }
    //     tmp1 = tmp1->next;
    // }
    // tmp1 = *head;
    buff3 = buff;
    // buff2 = buff;
    
    ft_next_queue(head, tmp1, buff, new_node);
    // while (tmp1)
    // {
    //     if (!ft_strcmp(tmp1->name_room, buff->n_r))
    //     {
    //         tmp1->use = 1;
    //         i = 0; 
    //         while (tmp1->link[i])
    //         {
    //             while(buff2->next)
    //             {
    //                 buff2 = buff2->next;
    //             }
    //             if (tmp1->link[i]->use != 1 && ft_queue(buff, tmp1->link[i]->name_room) == 1)
    //             {
    //                 // j++;
    //                 new_node = (t_road*)malloc(sizeof(t_road));
    //                 new_node->next = NULL;
    //                 new_node->n_r = ft_strdup(tmp1->link[i]->name_room);
    //                 tmp1->link[i]->from = ft_strdup(tmp1->name_room);
    //                 buff2->next = new_node;
    //                 // tmp1->link[i]->step = j;
    //             }
    //             i++;
    //         }
    //         buff = buff->next;
    //         if (tmp1->type_room == 2)
    //             break ;
    //         tmp1 = *head;
    //         continue ;
    //     }
    //     tmp1 = tmp1->next;
    // }
    while (buff3)
    {
        printf("%s", buff3->n_r);
        buff3 = buff3->next;
    }
    printf("\n");
    return (0);
}