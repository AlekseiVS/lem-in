/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_road.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:27:22 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/30 09:07:41 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>

static t_listlemin *ft_find_room(t_listlemin *buff, char *name_room)
{
    while (buff)
    {
        if (!ft_strcmp(name_room, buff->name_room))
            return (buff);
        buff = buff->next;
    }
    return (0);
}

static t_listlemin *ft_find_finish(t_listlemin *buff)
{
    while (buff)
    {
        if (buff->type_room == 2)
            return (buff);
        buff = buff->next;
    }
    return (0);
}

int ft_road(t_listlemin **head)
{
    t_listlemin *tmp;
    t_road *road;
    t_road *new_node;

    road = NULL;
    tmp = ft_find_finish(*head);
    if (!road)
    {
        road = (t_road*)malloc(sizeof(t_road));
        road->next = NULL;
        road->n_r = ft_strdup(tmp->name_room);
    }
    while (tmp->from)
    {
        new_node = (t_road*)malloc(sizeof(t_road));
        new_node->next = road;
        road = new_node;
        new_node->n_r = ft_strdup(tmp->from);
        tmp = ft_find_room(*head, new_node->n_r);
    }
    while (new_node)
    {
        printf("%s", new_node->n_r);
        new_node = new_node->next;
    }
    return (0);
}