/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:26:39 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:27:07 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_ant_in_q(t_path *p, int ant)
{
	int i;

	i = 0;
	while (p->prev_ants[i] != -1)
	{
		if (p->prev_ants[i] == ant)
			return ;
		i++;
	}
	p->prev_ants[i] = ant;
	p->ant_path[i] = 1;
	p->num_ants += 1;
}

void	remove_ant_from_q(t_path *p)
{
	int tmp;
	int i;

	i = 0;
	while (i + 1 < p->path_nodes)
	{
		tmp = p->prev_ants[i];
		p->prev_ants[i] = p->prev_ants[i + 1];
		p->prev_ants[i + 1] = tmp;
		tmp = p->ant_path[i];
		p->ant_path[i] = p->ant_path[i + 1];
		p->ant_path[i + 1] = tmp;
		i++;
	}
	p->prev_ants[i] = -1;
	p->ant_path[i] = 0;
	p->num_ants -= 1;
}
