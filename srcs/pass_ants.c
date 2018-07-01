/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:40:01 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:43:10 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_move(t_farm *f, t_path *tmp, int ant)
{
	if (f->ways_num > 1)
		color_print(tmp->prev_ants[ant], get_room_name(f,
					tmp->path[tmp->ant_path[ant]]), tmp->color);
	else
		color_print(tmp->prev_ants[ant],
				get_room_name(f, tmp->path[tmp->ant_path[ant]]),
							f->ant_color[tmp->prev_ants[ant]]);
}

int		move_previous(t_farm *f, int last)
{
	int		ant;
	t_path	*tmp;
	int		way;

	tmp = f->ways;
	way = -1;
	while (++way < f->ways_num)
	{
		ant = 0;
		while (ant < tmp->num_ants)
		{
			tmp->ant_path[ant] += 1;
			if (tmp->ant_path[ant] >= tmp->path_nodes)
			{
				remove_ant_from_q(tmp);
				ant = -1;
				last++;
			}
			else
				print_move(f, tmp, ant);
			ant++;
		}
		tmp = tmp->next;
	}
	return (last);
}

int		move_from_start(t_farm *f, int ant)
{
	t_path	*tmp;
	int		way;

	way = 0;
	tmp = f->ways;
	while (way < f->ways_num)
	{
		if (ant <= f->ants_num)
		{
			if (f->ways_num > 1)
				color_print(ant, get_room_name(f, tmp->path[1]), tmp->color);
			else
				color_print(ant, get_room_name(f,
										tmp->path[1]), f->ant_color[ant]);
			add_ant_in_q(tmp, ant);
			ant++;
		}
		tmp = tmp->next;
		way++;
	}
	return (ant);
}

void	pass_ants(t_farm *f)
{
	int	ant;
	int	last;

	color_array(f);
	ant = 1;
	last = 0;
	f->turns = 0;
	while (last < f->ants_num)
	{
		if (ant > 1)
			last = move_previous(f, last);
		if (ant <= f->ants_num)
			ant = move_from_start(f, ant);
		if (!(f->ways_num == 1 && f->ways->path_nodes == 2))
		{
			ft_printf("\n");
			f->turns++;
		}
	}
	if (f->ways_num == 1 && f->ways->path_nodes == 2)
	{
		f->turns += 2;
		ft_printf("\n\n");
	}
	print_paths(f);
}
