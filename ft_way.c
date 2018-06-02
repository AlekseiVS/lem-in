/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:30:19 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 22:06:14 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static	void	ft_c_sq(t_listlemin *tmp, t_road **start_q, t_road *n_n)
{
	int			i;

	i = 0;
	if (!n_n)
	{
		if (!tmp->link)
			exit(write(2, "ERROR\n", 6));
		n_n = ft_create_elem_2();
		*start_q = n_n;
		n_n->n_r = tmp->link[i]->name_room;
		tmp->link[i]->from = tmp->name_room;
		i++;
		while (tmp->link[i])
		{
			n_n->next = ft_create_elem_2();
			n_n = n_n->next;
			n_n->n_r = tmp->link[i]->name_room;
			tmp->link[i]->from = tmp->name_room;
			n_n->next = NULL;
			i++;
		}
	}
}

static	void	ft_s_q(t_listlemin *tmp, t_road **start_q, t_road *n_n)
{
	while (tmp)
	{
		if (tmp->type_room == 1)
		{
			tmp->use = 1;
			ft_c_sq(tmp, start_q, n_n);
			break ;
		}
		tmp = tmp->next;
	}
}

void			ft_c_nq(t_listlemin *tmp, t_road *start_q, t_road **end_q, t_road *n_n)
{
	int			i;

	i = 0;
	while (tmp->link[i])
	{
		while ((*end_q)->next)
			*end_q = (*end_q)->next;
		if (tmp->link[i]->use != 1 && ft_cmp_queue(start_q,
		tmp->link[i]->name_room) == 1)
		{
			n_n = ft_create_elem_2();
			n_n->n_r = tmp->link[i]->name_room;
			tmp->link[i]->from = tmp->name_room;
			(*end_q)->next = n_n;
		}
		i++;
	}
}

void			ft_n_q(t_listlemin *head, t_listlemin *tmp, t_road *start_q, t_road *n_n)
{
	t_road		*end_q;

	end_q = start_q;
	while (tmp)
	{
		if (!start_q)
			exit(write(2, "ERROR\n", 6));
		if (!ft_strcmp(tmp->name_room, start_q->n_r))
		{
			tmp->use = 1;
			ft_c_nq(tmp, start_q, &end_q, n_n);
			start_q = start_q->next;
			if (tmp->type_room == 2)
				break ;
			tmp = head;
			continue ;
		}
		tmp = tmp->next;
	}
}

void			ft_way(t_listlemin **head)
{
	t_listlemin	*tmp;
	t_road		*n_n;
	t_road		*start_q;
	t_road		*buff3;

	tmp = *head;
	n_n = NULL;
	start_q = NULL;
	ft_s_q(tmp, &start_q, n_n);
	buff3 = start_q;
	ft_n_q(*head, tmp, start_q, n_n);
	ft_del_2(&buff3);
}
