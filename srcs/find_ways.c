/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:37:20 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:38:11 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	count_steps(t_farm *f)
{
	if (f->steps == -1)
		f->steps = f->ants_num + (f->r[f->rooms_nb - 1].lvl - 1);
	else
		f->steps -= (f->r[f->rooms_nb - 1].lvl);
	if (f->steps <= 0)
		return (0);
	return (1);
}

int			find_ways(t_farm *f)
{
	int ret;

	create_graph(f);
	ret = 1;
	while (ret)
	{
		queue_init(f);
		if ((ret = find_path(f)))
		{
			add_path(f);
			if (!count_steps(f))
			{
				f->ways_num -= 1;
				break ;
			}
		}
		if (!f->multiple)
			break ;
	}
	if (!f->ways)
		return (ERROR);
	return (1);
}
