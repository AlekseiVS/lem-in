/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:54:03 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/31 15:40:16 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdio.h>

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
    tmp1 = head;
    ft_way(&tmp1);
    tmp1 = head;
    ft_road(&tmp1, ant);

    return (0);
}


