/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:54:03 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 18:55:46 by osokoliu         ###   ########.fr       */
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

static void ft_inicial(t_main *var)
{
    var->fd = 0;
    var->tg_s = 0;
    var->tg_e = 0;
    var->line = 0;
    var->ant = 0;
    var->type = 0;
}

int main()
{
    t_listlemin *head;
    t_listlemin *tmp;
    t_main      var;

    ft_inicial(&var);
    // int fd;
    // int tg_s;
    // int tg_e;
    // char *line;
    // int ant;
    // int type;
    // fd = 0;
    // tg_s = 0;
    // tg_e = 0;
    // line = 0;
    head = NULL;
    // ant = 0;
    // type = 0;
    
    if (fd == -1)
        exit(write(2, "ERROR\n", 6));   
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
        {
            free(line);
            break ;
        }
        free(line);
    }
    ft_enough_data(head);
    tmp = head;
    ft_way(&tmp);
    ft_road(&tmp, ant);
    system("leaks -quiet  lem-in"); 
    exit(1);
    return (0);
}


