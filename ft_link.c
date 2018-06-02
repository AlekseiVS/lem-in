/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:57:12 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 15:27:01 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

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
    exit(write(2, "ERROR\n", 6));
}

static void ft_vertex(char *line, t_vertex *vertex)
{
    char **buff;
    int     i;

    i = 0;
    buff = ft_strsplit(line, '-');
    vertex->u = ft_strdup(buff[0]);
    vertex->v = ft_strdup(buff[1]);
    while(buff[i] != NULL)
    {
        free(buff[i]);
        i++;
    }
    free(buff);
}

static void ft_entry_link(t_listlemin *tmp1, t_listlemin *tmp2)
{
    int i;
    t_listlemin **buff;
    
    i = 0;
    if (tmp1->link)
    {
        while(tmp1->link[i])
            i++;
        buff = (t_listlemin**)malloc(sizeof(t_listlemin*) * (i + 2));
        i = 0;
        while(tmp1->link[i])
        {
            buff[i] = tmp1->link[i];
            i++;
        }
        free(tmp1->link);
        tmp1->link = buff;
    }
    else
    {
        tmp1->link = (t_listlemin**)malloc(sizeof(t_listlemin*) * 2);
    }
    tmp1->link[i] = (t_listlemin*)malloc(sizeof(t_listlemin));
    tmp1->link[i] = tmp2;
    tmp1->link[i + 1] = 0;
}

static void ft_search_link(t_listlemin *tmp1, t_listlemin *tmp2, t_vertex vertex, int *count)
{
    while (tmp1)
    {
        if(ft_strequ(tmp1->name_room, vertex.u) == 1)
        {
            (*count)++;
            while (tmp2)
            {
                if (ft_strequ(tmp2->name_room, vertex.v) == 1)
                {
                    (*count)++;
                    break ;
                }
                tmp2 = tmp2->next;
            }
            if (!tmp1 || !tmp2)
                exit(write(1, "ERROR\n", 6));
            ft_entry_link(tmp1, tmp2);
            ft_entry_link(tmp2, tmp1);
            break ;
        }
        tmp1 = tmp1->next;
    }
}

int ft_link(char *line, t_listlemin **head)
{
    t_vertex vertex;
    t_listlemin *tmp1;
    t_listlemin *tmp2;
    int count;

    tmp1 = *head;
    tmp2 = *head;
    count = 0;
    if (ft_valid_link(line) == 1)
    {
        ft_vertex(line, &vertex);
        
        ft_search_link(tmp1, tmp2, vertex, &count);
        
        free(vertex.u);
        free(vertex.v);
       
        if (count == 2)
        {
            ft_putstr(line);
            write(1, "\n", 1);
            return (1);
        }
        else
            exit(write(2, "ERROR\n", 6));
    }
    
    return(0);
}