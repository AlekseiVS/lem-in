/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 21:20:08 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 21:57:03 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

void	ft_room_3(char *line, int space, int i)
{
	if (line[i] || space != 0)
		exit(write(2, "ERROR\n", 6));
	ft_putstr(line);
	write(1, "\n", 1);
}
