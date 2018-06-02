/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:55:29 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 22:37:17 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static	int		ft_valid_links(t_listlemin *head)
{
	while (head)
	{
		if (head->link)
			return (0);
		head = head->next;
	}
	return (1);
}

static	int		ft_valid_duble_room(t_listlemin *head,
				char *name_room, int x, int y)
{
	while (head)
	{
		if (!ft_strcmp(head->name_room, name_room))
			exit(write(2, "ERROR\n", 6));
		if (head->x == x && head->y == y)
			exit(write(2, "ERROR\n", 6));
		head = head->next;
	}
	return (1);
}

static	int		ft_valid_room(char *line)
{
	int			i;
	int			space;

	i = 0;
	space = 2;
	if (!ft_strchr(line, ' '))
		return (0);
	if (line[0] == 'L')
		exit(write(2, "ERROR\n", 6));
	while (line && line[i] != ' ')
		i++;
	while (line[i] == ' ' && line[i + 1] != ' ')
	{
		space--;
		i++;
		if (line[i] == '-')
			i++;
		while (ft_isdigit(line[i]) == 1)
			i++;
		if (space < 0)
			exit(write(2, "ERROR\n", 6));
	}
	ft_room_3(line, space, i);
	return (1);
}

static	void	ft_room2(t_listlemin **head,
				t_listlemin **new_node, int *type, char *line)
{
	int			j;
	int			i;

	j = 0;
	i = 0;
	if (!ft_valid_links(*head))
		exit(write(2, "ERROR\n", 6));
	(*new_node) = ft_create_elem();
	(*new_node)->type_room = *type;
	*type = 0;
	while (line[j] != ' ')
		j++;
	(*new_node)->name_room = ft_strnew(j);
	j = 0;
	while (line[j] != ' ')
		(*new_node)->name_room[i++] = line[j++];
	(*new_node)->x = ft_atoi(line + j);
	j++;
	while (line[j] != ' ')
		j++;
	(*new_node)->y = ft_atoi(line + j);
	if (!ft_valid_duble_room(*head, (*new_node)->name_room,
	(*new_node)->x, (*new_node)->y))
		exit(write(2, "ERROR\n", 6));
	ft_add_back(head, (*new_node));
}

int				ft_room(char *line, int *type, t_listlemin **head)
{
	int			i;
	int			j;
	t_listlemin *new_node;

	i = 0;
	j = 0;
	if (ft_valid_room(line) == 1)
	{
		ft_room2(head, &new_node, type, line);
		return (1);
	}
	return (0);
}
