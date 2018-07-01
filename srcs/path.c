/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:43:23 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:44:09 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	remove_path(t_farm *f, t_path *way)
{
	int		i;
	int		y;
	int		x;
	int		id;

	i = 0;
	if (way->path_nodes - 2 <= 0)
		i = -1;
	while (++i < way->path_nodes - 1)
	{
		id = way->path[i];
		y = -1;
		while (++y < f->rooms_nb)
			f->graph[y][id] = 0;
		x = -1;
		while (++x < f->rooms_nb)
			f->graph[id][x] = 0;
	}
	if (f->r[f->rooms_nb - 1].path)
	{
		free(f->r[f->rooms_nb - 1].path);
		f->r[f->rooms_nb - 1].path = NULL;
	}
}

t_path	*create_path(t_farm *f)
{
	t_path	*way;
	int		end;
	int		i;

	end = f->rooms_nb - 1;
	way = (t_path*)malloc(sizeof(t_path));
	way->path = (int*)ft_memalloc(sizeof(int) * (f->r[end].lvl + 1));
	way->path_nodes = f->r[end].lvl + 1;
	i = -1;
	while (++i < f->r[end].lvl)
		way->path[i] = f->r[end].path[i];
	way->path[i] = end;
	way->num_ants = 0;
	way->prev_ants = (int*)ft_memalloc(sizeof(int) * way->path_nodes);
	way->ant_path = (int*)ft_memalloc(sizeof(int) * way->path_nodes);
	i = -1;
	while (++i < way->path_nodes)
		way->prev_ants[i] = -1;
	remove_path(f, way);
	way->next = NULL;
	return (way);
}

void	add_path_to_list(t_path **ways, t_path *new)
{
	t_path *temp;

	temp = *ways;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void	add_path(t_farm *f)
{
	if (!f->ways)
		f->ways = create_path(f);
	else
		add_path_to_list(&f->ways, create_path(f));
	f->ways_num++;
}
