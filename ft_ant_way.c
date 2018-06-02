/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 09:57:37 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 21:42:39 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static	t_road	*ft_find_finish(t_road *buff)
{
	while (buff)
	{
		if (buff->next == NULL)
			return (buff);
		buff = buff->next;
	}
	return (0);
}

static	void	ft_arry_ant(t_road *road, t_ant **ant_arry, int ant)
{
	t_ant		ant_s;
	int			i;
	int			j;

	*ant_arry = (t_ant*)malloc(sizeof(t_ant) * ant);
	i = 0;
	j = 1;
	while (i < ant)
	{
		ant_s.path = road;
		ant_s.name_ant = j++;
		ant_s.fin = 0;
		(*ant_arry)[i] = ant_s;
		i++;
	}
}

static void		ft_print(int n, char *s)
{
	write(1, "L", 1);
	ft_putnbr(n);
	write(1, "-", 1);
	ft_putstr(s);
}

static	void	ft_ant_w2(t_ant **ant_arry, t_road **end, int *print, int ant)
{
	int			i;

	i = 0;
	while (i < ant)
	{
		if ((*ant_arry)[i].path->next != NULL &&
		(*ant_arry)[i].path->next->tg == 0)
		{
			if (*print == 1)
				write(1, " ", 1);
			(*ant_arry)[i].path->next->tg = 1;
			(*ant_arry)[i].path->tg = 0;
			(*ant_arry)[i].path = (*ant_arry)[i].path->next;
			ft_print((*ant_arry)[i].name_ant, (*ant_arry)[i].path->n_r);
			*print = 1;
		}
		else if ((*ant_arry)[i].path->next == NULL && !(*ant_arry)[i].fin)
		{
			(*end)->ant_room++;
			(*ant_arry)[i].fin++;
			(*ant_arry)[i].path->tg = 0;
		}
		i++;
	}
}

void			ft_ant_way(t_road *road, int ant)
{
	t_ant		*ant_arry;
	t_road		*end;
	int			print;

	ft_arry_ant(road, &ant_arry, ant);
	end = ft_find_finish(road);
	while (1)
	{
		print = 0;
		ft_ant_w2(&ant_arry, &end, &print, ant);
		if (end->ant_room == ant)
			break ;
		write(1, "\n", 1);
	}
	free(ant_arry);
}
