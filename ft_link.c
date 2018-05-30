/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:57:12 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/30 09:41:03 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>

static int ft_valid_link(char *line)
{
    int i;
    int count;
    
    i = 0;
    count = 0;
    while(line[i] && (line[i]) != ' ')
    {   
        i++;
        if(line[i] == '-')
        {
            i++;
            count++;
        }
    }
    if (line[i] == '\0' && count == 1)
    {
        return (1);
    }
    exit(printf("ERROR\n"));
}

static void ft_vertex(char *line, t_vertex *vertex)
{
    char **buff;
    
    buff = ft_strsplit(line, '-');
    vertex->u = buff[0];
    vertex->v = buff[1];
}

static void ft_entry_link(t_listlemin *tmp1, t_listlemin *tmp2)
{
    int i;

    i = 0;
    if (tmp1->link)
    {
        while(tmp1->link[i])
        i++;
    }
    else
    {
        tmp1->link = (t_listlemin**)malloc(sizeof(t_listlemin*));
    }
    tmp1->link[i] = (t_listlemin*)malloc(sizeof(t_listlemin) * 0);
    tmp1->link[i] = tmp2;
    tmp1->link[i + 1] = 0;
}

int ft_link(char *line, t_listlemin **head)
{
    t_vertex vertex;
    t_listlemin *tmp1;
    t_listlemin *tmp2;
    int count;
    // int i;

    count = 0;
    if (ft_valid_link(line) == 1)
    {
        ft_vertex(line, &vertex);
        tmp1 = *head;
        while (tmp1)
        {
            if(ft_strequ(tmp1->name_room, vertex.u) == 1)
            {
                count++;
                tmp2 = *head;
                while (tmp2)
                {
                    if (ft_strequ(tmp2->name_room, vertex.v) == 1)
                    {
                        count++;
                        break ;
                    }
                    tmp2 = tmp2->next;
                }
                ft_entry_link(tmp1, tmp2);
                ft_entry_link(tmp2, tmp1);
                // i = 0;
                // if (tmp1->link)
                // {
                //     while(tmp1->link[i])
                //         i++;
                // }
                // else
                // {
                //     tmp1->link = (t_listlemin**)malloc(sizeof(t_listlemin*));
                // }
                // tmp1->link[i] = (t_listlemin*)malloc(sizeof(t_listlemin) * 0);
                // tmp1->link[i] = tmp2;
                // tmp1->link[i + 1] = 0;
                // i = 0;
                // if (tmp2->link)
                // {
                //     while(tmp2->link[i])
                //         i++;
                // }
                // else
                // {
                //     tmp2->link = (t_listlemin**)malloc(sizeof(t_listlemin*));
                // }
                // tmp2->link[i] = (t_listlemin*)malloc(sizeof(t_listlemin) * 0);
                // tmp2->link[i] = tmp1;
                // tmp2->link[i + 1] = 0;
                break ;
            }
            tmp1 = tmp1->next;
        }
        if (count == 2)
        {
            printf("%s\n", line);
            return (1);
        }
        else
            exit(printf("ERROR"));
    }
    return(0);
}