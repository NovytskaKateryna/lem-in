/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:34:54 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:35:13 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	display_description(t_farm *f)
{
	t_list *tmp;

	tmp = f->description;
	while (tmp->next)
	{
		ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	if (!f->e.error)
		ft_printf("%s\n", tmp->content);
	ft_printf("\n");
}

void	write_description(t_farm *f, const char *line)
{
	if (!(f->description))
		f->description = ft_lstnew(line, ft_strlen(line) + 1);
	else
		ft_lstback(&f->description, ft_lstnew(line, ft_strlen(line) + 1));
}
