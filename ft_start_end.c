/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:55:18 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 22:00:27 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

int	ft_start_end(char *line, int *type, int *tg_s, int *tg_e)
{
	if (line[0] == '#')
	{
		if (ft_strcmp(line, "##start") == 0)
		{
			if (*tg_s == 1)
				exit(write(2, "ERROR\n", 6));
			*tg_s = 1;
			*type = 1;
			ft_putstr(line);
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			if (*tg_e == 1)
				exit(write(2, "ERROR\n", 6));
			*tg_e = 1;
			*type = 2;
			ft_putstr(line);
		}
		else
			ft_putstr(line);
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}
