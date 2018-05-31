/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 11:55:54 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/31 10:09:38 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	struct s_road	*next;
}					t_road;

typedef struct		s_ant
{
	int 			name_ant;
	struct s_road	*path;
}					t_ant;

int					ft_ant(char *line, int *ant);
int					ft_start_end(char *line, int *type);
int					ft_room(char *line, int *type, t_listlemin **head);
int					ft_link(char *line, t_listlemin **head);
t_listlemin 		*ft_create_elem(void);
void				ft_add_back(t_listlemin **head, t_listlemin *new_node);
int					ft_way(t_listlemin **head);
t_road 				*ft_create_elem_2(void);
void 				ft_add_back_2(t_road **head, t_road *new_node);
int					ft_road(t_listlemin **head, int ant);
int					ft_cmp_queue(t_road *buff, char *name_room);
void				ft_ant_way(t_road *road, int ant);