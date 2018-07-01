/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:44:22 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:44:45 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_element(t_farm *f, int elem, int parent)
{
	int i;

	i = 0;
	while (f->q[i] != -1)
	{
		if (f->q[i] == elem)
			return ;
		i++;
	}
	f->q[i] = elem;
	f->prev[elem] = parent;
}

int		queue_len(int *q)
{
	int len;

	len = 0;
	while (q[len] != -1)
		len++;
	return (len);
}

int		remove_from_q(t_farm *f)
{
	int elem;
	int tmp;
	int i;

	elem = f->q[0];
	i = 0;
	while (i + 1 < f->rooms_nb)
	{
		tmp = f->q[i];
		f->q[i] = f->q[i + 1];
		f->q[i + 1] = tmp;
		i++;
	}
	f->q[i] = -1;
	return (elem);
}

void	queue_init(t_farm *f)
{
	int x;

	if (!f->q && !f->visited && !f->prev)
	{
		f->q = (int*)ft_memalloc(sizeof(int) * f->rooms_nb);
		f->visited = (int*)ft_memalloc(sizeof(int) * f->rooms_nb);
		f->prev = (int*)ft_memalloc(sizeof(int) * f->rooms_nb);
	}
	x = -1;
	while (++x < f->rooms_nb)
	{
		f->visited[x] = 0;
		f->prev[x] = 0;
	}
	f->visited[0] = 1;
	x = -1;
	while (++x < f->rooms_nb)
		f->q[x] = -1;
}
