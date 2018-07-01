/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:12:23 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 16:03:03 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BROWN "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define LIGHT_GRAY "\033[0;37m"
# define DARK_GRAY "\033[1;30m"
# define LIGHT_RED "\033[1;31m"
# define LIGHT_GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define LIGHT_BLUE "\033[1;34m"
# define LIGHT_PURPLE "\033[1;35m"
# define LIGHT_CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define EOC "\033[0m"

# define INT_MAX 2147483647
# define ERROR 0

# define X 0
# define Y 1

typedef struct		s_path
{
	int				*path;
	int				path_nodes;
	int				*prev_ants;
	int				*ant_path;
	int				num_ants;
	int				color;
	struct s_path	*next;
}					t_path;

typedef	struct		s_r
{
	int				*path;
	int				lvl;
}					t_r;

typedef	struct		s_link
{
	char			*name1;
	int				name1_id;
	char			*name2;
	int				name2_id;
	struct s_link	*next;
}					t_link;

typedef	struct		s_room
{
	char			*name;
	int				coords[2];
	char			type;
	int				id;
	struct s_room	*next;
}					t_room;

typedef struct		s_error
{
	int				error;
	int				start_cmd;
	int				start_cmd_on;
	int				end_cmd;
	int				end_cmd_on;
	int				start_room;
	int				end_room;
	int				room_exist;
	int				invalid_name;
	int				reading_links;
	int				end_linked;
	int				start_linked;
}					t_error;

typedef struct		s_farm
{
	int				ants_num;
	t_error			e;
	t_room			*rooms;
	t_link			*links;
	t_list			*description;
	t_r				*r;
	t_path			*ways;
	int				rooms_nb;
	int				**graph;
	int				*q;
	int				*visited;
	int				*prev;
	int				*ant_color;
	int				ways_num;
	int				multiple;
	int				turns;
	int				steps;
}					t_farm;

int					line_analize(t_farm *f, char *line);
int					check_line_on_int(char *line);
int					check_for_ants(t_farm *f, char *line);
int					check_room(t_farm *f, char *line, char type);
int					check_link(t_farm *f, char *line);
int					check_start_end(t_farm *f, char *line);
int					check_room_exist(t_farm *f, char *name);
int					check_link_exist(t_farm *f, char **split);
int					check_room_coords(t_farm *f, char **split);
int					check_start(t_farm *f, char *line);
int					check_end(t_farm *f, char *line);
void				errors(t_farm *f);
void				error_msg(void);
void				add_room(t_farm *f, char **split, char type);
void				assign_room_ids(t_farm *f);
int					get_room_id(t_farm *f, char *room);
void				add_link(t_farm *f, char **split);
char				*get_room_name(t_farm *f, int id);
void				write_description(t_farm *f, const char *line);
void				display_description(t_farm *f);
int					find_path(t_farm *f);
void				create_graph(t_farm *f);
int					find_ways(t_farm *f);
void				add_path(t_farm *f);
void				pass_ants(t_farm *f);
void				add_ant_in_q(t_path *p, int ant);
void				remove_ant_from_q(t_path *p);
void				color_print(int ant_num, char *room, int color);
void				color_array(t_farm *f);
void				print_paths(t_farm *f);
void				queue_init(t_farm *f);
int					queue_len(int *q);
int					remove_from_q(t_farm *f);
void				add_element(t_farm *f, int elem, int parent);

#endif
