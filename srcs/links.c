/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:39:25 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:39:46 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*get_room_name(t_farm *f, int id)
{
	t_room *tmp;

	tmp = f->rooms;
	while (tmp)
	{
		if (tmp->id == id)
			return (tmp->name);
		tmp = tmp->next;
	}
	return (NULL);
}

t_link	*create_link(t_farm *f, char **split)
{
	t_link *link;

	link = (t_link*)malloc(sizeof(t_link));
	link->name1 = ft_strdup(split[0]);
	link->name2 = ft_strdup(split[1]);
	link->name1_id = get_room_id(f, link->name1);
	link->name2_id = get_room_id(f, link->name2);
	link->next = NULL;
	return (link);
}

void	add_link_to_list(t_link **links, t_link *new)
{
	t_link *temp;

	temp = *links;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void	add_link(t_farm *f, char **split)
{
	if (!f->links)
		f->links = create_link(f, split);
	else
		add_link_to_list(&f->links, create_link(f, split));
}
