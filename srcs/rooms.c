/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:44:57 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:45:56 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*create_room(char **split, char type)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name = ft_strdup(split[0]);
	room->coords[X] = ft_atoi(split[1]);
	room->coords[Y] = ft_atoi(split[2]);
	room->type = type;
	room->next = NULL;
	return (room);
}

void	add_room_to_list(t_room **rooms, t_room *new)
{
	t_room *temp;

	temp = *rooms;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void	add_room(t_farm *f, char **split, char type)
{
	if (!f->rooms)
		f->rooms = create_room(split, type);
	else
		add_room_to_list(&f->rooms, create_room(split, type));
	f->rooms_nb++;
}

int		get_room_id(t_farm *f, char *room)
{
	t_room *tmp;

	tmp = f->rooms;
	while (tmp)
	{
		if (ft_strequ(tmp->name, room))
			return (tmp->id);
		tmp = tmp->next;
	}
	return (0);
}

void	assign_room_ids(t_farm *f)
{
	int		id;
	t_room	*tmp;

	id = 1;
	tmp = f->rooms;
	while (tmp)
	{
		if (tmp->type == 's')
			tmp->id = 0;
		else if (tmp->type == 'e')
			tmp->id = f->rooms_nb - 1;
		else if (tmp->type == 'n')
		{
			tmp->id = id;
			id++;
		}
		tmp = tmp->next;
	}
}
