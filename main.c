/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:54:03 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 22:09:19 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static	void	ft_enough_data(t_listlemin *head)
{
	int			i;
	t_listlemin	*tmp;

	i = 0;
	tmp = head;
	while (head)
	{
		if (head->type_room == 2 || head->type_room == 1)
			i++;
		head = head->next;
	}
	if (i != 2)
		exit(write(2, "ERROR\n", 6));
}

static	void	ft_inicial(t_m *var)
{
	var->fd = 0;
	var->tg_s = 0;
	var->tg_e = 0;
	var->line = 0;
	var->ant = 0;
	var->type = 0;
}

void			ft_pars1(t_m *var, t_listlemin **head)
{
	while (get_next_line(var->fd, &(var->line)))
	{
		if (!var->line[0])
			exit(write(2, "ERROR\n", 6));
		else if (ft_ant(var->line, &(var->ant)) == 1)
			;
		else if (ft_start_end(var->line, &(var->type), &(var->tg_s), &(var->tg_e)) == 1)
			;
		else if (ft_room(var->line, &(var->type), head) == 1)
			;
		else if (ft_link(var->line, head) == 1)
			;
		else
		{
			free(var->line);
			break ;
		}
		free(var->line);
	}
}

int				main(void)
{
	t_listlemin	*head;
	t_listlemin	*tmp;
	t_m			var;

	head = NULL;
	ft_inicial(&var);
	if (var.fd == -1)
		exit(write(2, "ERROR\n", 6));
	ft_pars1(&var, &head);
	ft_enough_data(head);
	tmp = head;
	ft_way(&tmp);
	ft_road(&tmp, var.ant);
	return (0);
}
