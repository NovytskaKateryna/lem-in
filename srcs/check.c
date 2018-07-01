/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:27:24 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:31:29 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_for_ants(t_farm *f, char *line)
{
	int		ret;

	ret = 1;
	if (!check_line_on_int(line))
		ret = ERROR;
	if (ft_atoi(line) == 0)
		ret = ERROR;
	if (ret)
		f->ants_num = ft_atoi(line);
	return (ret);
}

int		check_name(char *name)
{
	int i;

	if (has_char(name, '-'))
		return (ERROR);
	i = -1;
	while (name[++i])
	{
		if (!ft_isprint(name[i]))
			return (1);
	}
	return (ERROR);
}

int		check_room(t_farm *f, char *line, char type)
{
	char	**split;
	int		ret;

	ret = 1;
	if (count_spaces(line) != 2)
		return (ERROR);
	split = ft_strsplit(line, ' ');
	if (!check_comp_num(split, 3))
	{
		free_array(split);
		return (ERROR);
	}
	if (!check_line_on_int(split[1]) ||
		!check_line_on_int(split[2]))
		ret = ERROR;
	if (split[0][0] == 'L' || split[0][0] == '#')
		ret = ERROR;
	if ((f->e.invalid_name = check_name(split[0])) ||
		(f->e.room_exist = check_room_exist(f, split[0])) ||
		(f->e.room_exist = check_room_coords(f, split)))
		ret = ERROR;
	if (ret)
		add_room(f, split, type);
	free_array(split);
	return (ret);
}

int		check_start_end(t_farm *f, char *line)
{
	if (ft_strequ(line, "##start"))
	{
		if (!f->ants_num)
			return (ERROR);
		if (!f->e.start_cmd)
			f->e.start_cmd_on = 1;
		f->e.start_cmd++;
		if (f->e.start_cmd > 1)
			f->e.error = 1;
	}
	else if (ft_strequ(line, "##end"))
	{
		if (!f->ants_num)
			return (ERROR);
		if (!f->e.end_cmd)
			f->e.end_cmd_on = 1;
		f->e.end_cmd++;
		if (f->e.end_cmd > 1)
			f->e.error = 1;
	}
	return (1);
}

int		check_link(t_farm *f, char *line)
{
	char	**split;

	if (count_spaces(line) != 0)
		f->e.error = 1;
	if (!(split = ft_strsplit(line, '-')))
	{
		f->e.error = 1;
		return (1);
	}
	if (!check_comp_num(split, 2))
		f->e.error = 1;
	if (!check_room_exist(f, split[0]) ||
		!check_room_exist(f, split[1]) ||
		ft_strequ(split[0], split[1]))
		f->e.error = 1;
	if (!(check_link_exist(f, split)) && !(f->e.error))
		add_link(f, split);
	free_array(split);
	return (1);
}
