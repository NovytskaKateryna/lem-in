/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:35:28 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:35:55 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error_msg(void)
{
	ft_printf("{red}ERROR{eoc}\n");
	exit(1);
}

void	errors(t_farm *f)
{
	if (!f->ants_num)
		error_msg();
	else if (!f->rooms)
		error_msg();
	else if (!f->links)
		error_msg();
	else if (!f->e.start_room)
		error_msg();
	else if (!f->e.end_room)
		error_msg();
	else if (!f->e.start_linked)
		error_msg();
	else if (!f->e.end_linked)
		error_msg();
	else if (f->e.invalid_name && !f->e.error)
		error_msg();
	else if (f->e.room_exist && !f->e.error)
		error_msg();
	else if (f->e.start_cmd > 1 && !f->e.error)
		error_msg();
	else if (f->e.end_cmd > 1 && !f->e.error)
		error_msg();
}
