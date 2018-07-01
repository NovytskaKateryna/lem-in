/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:36:10 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/05 10:09:17 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	create_graph(t_farm *f)
{
	t_link *tmp;

	tmp = f->links;
	f->graph = create_tab(f->rooms_nb, f->rooms_nb);
	f->r = (t_r*)ft_memalloc(sizeof(t_r) * f->rooms_nb);
	while (tmp)
	{
		f->graph[tmp->name1_id][tmp->name2_id] = 1;
		f->graph[tmp->name2_id][tmp->name1_id] = 1;
		tmp = tmp->next;
	}
}

void	path_to_node(t_farm *f, int id)
{
	int		prev;
	t_r		*room;
	int		i;

	prev = f->prev[id];
	room = f->r;
	room[id].lvl = room[prev].lvl + 1;
	ft_memdel((void*)&room[id].path);
	room[id].path = (int*)ft_memalloc(sizeof(int) * (room[id].lvl + 1));
	i = -1;
	while (++i < room[prev].lvl)
		room[id].path[i] = room[prev].path[i];
	room[id].path[i] = f->prev[id];
}

void	check_visited(t_farm *f, int node)
{
	int x;

	x = -1;
	while (++x < f->rooms_nb)
	{
		if (f->graph[node][x] == 1 && f->visited[x] == 0)
		{
			f->visited[x] = 1;
			add_element(f, x, node);
		}
	}
}

int		find_path(t_farm *f)
{
	int node;
	int queue_empty;

	node = 0;
	queue_empty = 0;
	while (!queue_empty)
	{
		check_visited(f, node);
		if (queue_len(f->q) == 0)
			queue_empty = 1;
		else
		{
			node = remove_from_q(f);
			path_to_node(f, node);
			if (node == (f->rooms_nb - 1))
				break ;
		}
	}
	if (!f->r[f->rooms_nb - 1].path)
		return (ERROR);
	return (1);
}
