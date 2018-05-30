/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way_cmp_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:11:10 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/30 12:11:51 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>

int ft_cmp_queue(t_road *buff, char *name_room)
{
    while (buff)
    {
        if (!ft_strcmp(name_room, buff->n_r))
            return (0);
        buff = buff->next;
    }
    return (1);
}