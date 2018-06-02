/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:21:51 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 16:27:04 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

t_listlemin *ft_create_elem(void)
{
    t_listlemin *new_node;

    new_node = (t_listlemin*)malloc(sizeof(t_listlemin));
    ft_bzero(new_node, sizeof(t_listlemin));
    new_node->next = NULL;
    return (new_node);
}

void ft_add_back(t_listlemin **head, t_listlemin *new_node)
{
    t_listlemin *tmp;
    if (!(*head))
    {
        *head = new_node;
        return ;
    }
    tmp = *head;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
}



t_road *ft_create_elem_2(void)
{
    t_road *new_node;

    new_node = (t_road*)malloc(sizeof(t_road));
    ft_bzero(new_node, sizeof(t_road));
    new_node->next = NULL;
    return (new_node);
}

void ft_add_back_2(t_road **head, t_road *new_node)
{
    t_road *tmp;
    if (!(*head))
    {
        *head = new_node;
        return ;
    }
    tmp = *head;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
}