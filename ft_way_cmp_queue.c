/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way_cmp_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:11:10 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 11:17:52 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

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