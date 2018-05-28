/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:55:29 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/24 12:23:34 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>

static int ft_valid_room(char *line)
{
    int i;
    int space;
    
    i = 0;
    space = 2;
    if (ft_strchr(line, '-'))
        return (0);
    while(line && line[i] != ' ')
        i++;
    while (line[i] == ' ' && line[i+1] != ' ')
    {
        space--;
        i++;
        while(ft_isdigit(line[i]) == 1)
            i++;
        if (space < 0)
            exit(printf("ERROR\n"));
    }
    if (line[i] || space != 0)
        exit(printf("ERROR\n"));
    printf("%s\n", line);
    return (1);
}

int ft_room(char *line, int *type, t_listlemin **head)
{
    int i;
    int j;
    t_listlemin *new_node;

    i = 0;
    j = 0;
    if (ft_valid_room(line) == 1)
    {
        new_node = ft_create_elem();
        new_node->type_room = *type;
        *type = 0;
        while (line[j] != ' ')
            j++;
        new_node->name_room = ft_strnew(j);
        j = 0;
        while (line[j] != ' ')
            new_node->name_room[i++] = line[j++];
        new_node->x = ft_atoi(line + j);
        j++;
        while (line[j] != ' ')
            j++;
        new_node->y = ft_atoi(line + j);
        ft_add_back(head, new_node);
        return (1);
    } 
    return (0);
}