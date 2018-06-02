/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:54:03 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 09:47:29 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>

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


int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        exit(printf("ERROR\n"));
    // setbuf(stdout, NULL);

    int tg_s;
    int tg_e;
    
    tg_s = 0;
    tg_e = 0;
    // Убрать -g(Для дебагинга) с make file!!!!!!!!!!

    int b = argc;
    b++;
    char *line = 0;
    
    t_listlemin *head;
    int ant = 0;
    int type = 0;
    head = NULL;

    t_listlemin *tmp1;   
    while(get_next_line(fd, &line))
    {
        if (!line[0])
            exit(printf("ERROR\n"));
        else if (ft_ant(line, &ant) == 1)
            ;
        else if (ft_start_end(line, &type, &tg_s, &tg_e) == 1)
            ;
        else if (ft_room(line, &type, &head) == 1)
            ;
        else if (ft_link(line, &head) == 1)
            ;
        else
            exit(printf("ERROR\n"));
    }
    // tmp1 = head;
    // int i;
    // while (tmp1)
    // {   
    //     printf("%s", tmp1->name_room);
    //     i = 0;
    //     while(tmp1->link[i])
    //     {
    //         printf("->%s", tmp1->link[i]->name_room);
    //         i++;
    //     }
    //     printf("\n");
    //     tmp1 = tmp1->next;

    // }
    
    //Проверить или в старт и енд есть хоть один линк

    ft_enough_data(head);
    tmp1 = head;
    ft_way(&tmp1);
    
    tmp1 = head;
    ft_road(&tmp1, ant);

    // system("leaks -quiet lemin");

    return (0);
}


