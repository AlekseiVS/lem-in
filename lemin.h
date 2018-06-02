/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 11:55:54 by osokoliu          #+#    #+#             */
/*   Updated: 2018/06/02 18:52:35 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <limits.h>
# include <stdio.h>

typedef struct			s_listlemin
{
	struct s_listlemin 	**link;
	char				*name_room;
	int					type_room;
	int					x;
	int 				y;
	int					step;
	int					use;
	char				*from;
	struct s_listlemin	*next;
}						t_listlemin;

typedef struct		s_vertex
{
	char			*u;
	char			*v;
}					t_vertex;

typedef struct		s_road
{
	char			*n_r;
	int				tg;
	int				ant_room;
	struct s_road	*next;
}					t_road;

typedef struct		s_ant
{
	int 			name_ant;
	int				fin;
	struct s_road	*path;
}					t_ant;



typedef struct		s_main
{
	int 			fd;
    int 			tg_s;
    int 			tg_e;
    char 			*line;
    int 			ant;
    int 			type;
}					t_main;







int					ft_ant(char *line, int *ant);
int					ft_start_end(char *line, int *type, int *tg_s, int *tg_e);
int					ft_room(char *line, int *type, t_listlemin **head);
int					ft_link(char *line, t_listlemin **head);
t_listlemin 		*ft_create_elem(void);
void				ft_add_back(t_listlemin **head, t_listlemin *new_node);
void				ft_way(t_listlemin **head);
t_road 				*ft_create_elem_2(void);
void 				ft_add_back_2(t_road **head, t_road *new_node);
void				ft_road(t_listlemin **head, int ant);
int					ft_cmp_queue(t_road *buff, char *name_room);
void				ft_ant_way(t_road *road, int ant);
void 				ft_del_1(t_listlemin *head);
void 				ft_del_2(t_road **head);
#endif