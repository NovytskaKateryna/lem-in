/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_analize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:38:29 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:39:13 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_line_on_int(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]))
			return (ERROR);
	}
	if (ft_strlen(line) > 10)
		return (ERROR);
	if (ft_atoi(line) < 0)
		return (ERROR);
	if (ft_atoi(line) > (INT_MAX - 1))
		return (ERROR);
	return (1);
}

int		check_link_format(t_farm *f, char *line)
{
	int pos;

	pos = find_pos(line, '-');
	if (pos + 1 < (int)ft_strlen(line) && pos - 1 >= 0)
	{
		if (f->ants_num && f->rooms)
		{
			f->e.reading_links = 1;
			assign_room_ids(f);
			return (check_link(f, line));
		}
		else
			f->e.error = 1;
	}
	return (1);
}

int		line_analize(t_farm *f, char *line)
{
	if (!f->ants_num && line[0] != '#')
		return (check_for_ants(f, line));
	if (has_char(line, '-') && line[0] != '#')
		return (check_link_format(f, line));
	else if (line[0] != '#' &&
			(f->e.end_cmd_on && !f->e.start_cmd_on) && !f->e.end_room)
		return (check_end(f, line));
	else if (line[0] != '#' &&
			(f->e.start_cmd_on && !f->e.end_cmd_on) && !f->e.start_room)
		return (check_start(f, line));
	else if (line[0] == '#')
		return (check_start_end(f, line));
	else
	{
		if (!f->e.reading_links)
			return (check_room(f, line, 'n'));
		else
			f->e.error = 1;
	}
	return (0);
}
