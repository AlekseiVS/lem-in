/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:54:03 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 11:23:25 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

void ft_enough_data(t_listlemin *head)
{
    int i;
    t_listlemin *tmp;

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


int main(void)
{
    int fd = 0;
    if (fd == -1)
        exit(write(2, "ERROR\n", 6));

    int tg_s;
    int tg_e;
    
    tg_s = 0;
    tg_e = 0;

    char *line = 0;
    
    t_listlemin *head;
    int ant = 0;
    int type = 0;
    head = NULL;

    t_listlemin *tmp;   
    while(get_next_line(fd, &line))
    {
        if (!line[0])
            exit(write(2, "ERROR\n", 6));
        else if (ft_ant(line, &ant) == 1)
            ;
        else if (ft_start_end(line, &type, &tg_s, &tg_e) == 1)
            ;
        else if (ft_room(line, &type, &head) == 1)
            ;
        else if (ft_link(line, &head) == 1)
            ;
        else
            exit(write(2, "ERROR\n", 6));
    }
    
    ft_enough_data(head);
    tmp = head;
    ft_way(&tmp);
    tmp = head;
    ft_road(&tmp, ant);

    // system("leaks -quiet lemin");

    return (0);
}


