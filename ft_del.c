/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 12:56:30 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 21:45:39 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

void	ft_del_2(t_road **head)
{
	t_road *tmp;

	tmp = *head;
	while (tmp)
	{
		free(tmp);
		tmp = tmp->next;
	}
}
