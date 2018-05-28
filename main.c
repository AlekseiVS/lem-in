/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:54:03 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/28 15:21:56 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>


// t_listlemin *create_elem(void)
// {
//     t_listlemin *new_node;

//     new_node = (t_listlemin*)malloc(sizeof(t_listlemin));
//     ft_bzero(new_node, sizeof(t_listlemin));
//     return (new_node);
// }

// void add_back(t_listlemin **head, t_listlemin *new_node)
// {
//     t_listlemin *tmp;
//     if (!(*head))
//     {
//         *head = new_node;
//         return ;
//     }
//     tmp = *head;
//     while(tmp->next != NULL)
//         tmp = tmp->next;
//     tmp->next = new_node;
// }


int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        exit(printf("ERROR\n"));

    int b = argc;
    b++;
    char *line = 0;
    
    t_listlemin *head;
    int ant = 0;
    int type = 0;
    head = NULL;

    t_listlemin *tmp1;
    // t_listlemin *tmp2;    



    while(get_next_line(fd, &line))
    {
        if (!line[0])
            exit(printf("ERROR\n"));
        else if (ft_ant(line, &ant) == 1)
            ;
        else if (ft_start_end(line, &type) == 1)
            ;
        else if (ft_room(line, &type, &head) == 1)
            ;
        else if (ft_link(line, &head) == 1)
            ;
        else
            exit(printf("ERROR\n"));
    }
    // while (head)
    // {
    //     printf("%d", head->type_room);
    //     head = head->next;
    // }
    tmp1 = head;
    while (tmp1)
    {
        printf("%s-%d", tmp1->name_room, tmp1->type_room);
        int i = 0;
        while(tmp1->link[i])
        {
            printf("->%s", tmp1->link[i]->name_room);
            i++;
        }
        printf("\n");
        tmp1 = tmp1->next;
    }

    tmp1 = head;
    ft_way(&tmp1);
    
    tmp1 = head;
    while (tmp1)
    {
        printf("%d-%d\n", tmp1->use, tmp1->step);
        tmp1 = tmp1->next;
    }

    return (0);
}


