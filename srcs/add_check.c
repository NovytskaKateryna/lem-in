/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:21:51 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:26:25 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_start(t_farm *f, char *line)
{
	if (!f->ants_num)
		return (ERROR);
	if (check_room(f, line, 's'))
		f->e.start_room = 1;
	else
		return (ERROR);
	f->e.start_cmd_on = 0;
	return (1);
}

int		check_end(t_farm *f, char *line)
{
	if (!f->ants_num)
		return (ERROR);
	if (check_room(f, line, 'e'))
		f->e.end_room = 1;
	else
		return (ERROR);
	f->e.end_cmd_on = 0;
	return (1);
}

int		check_room_exist(t_farm *f, char *name)
{
	t_room *tmp;

	tmp = f->rooms;
	while (tmp)
	{
		if (ft_strequ(name, tmp->name))
		{
			if (tmp->type == 's' && !f->e.start_linked)
				f->e.start_linked = 1;
			else if (tmp->type == 'e' && !f->e.end_linked)
				f->e.end_linked = 1;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		check_link_exist(t_farm *f, char **split)
{
	t_link *tmp;

	tmp = f->links;
	while (tmp)
	{
		if ((ft_strequ(split[0], tmp->name1) &&
			ft_strequ(split[1], tmp->name2)) ||
			(ft_strequ(split[1], tmp->name1) &&
			ft_strequ(split[0], tmp->name2)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		check_room_coords(t_farm *f, char **split)
{
	t_room *tmp;

	tmp = f->rooms;
	while (tmp)
	{
		if (tmp->coords[X] == ft_atoi(split[1]) &&
			tmp->coords[Y] == ft_atoi(split[2]))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
