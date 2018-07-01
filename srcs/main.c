/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:20:27 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:21:35 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	param_init(t_farm *f)
{
	f->description = NULL;
	f->rooms = NULL;
	f->links = NULL;
	f->ways = NULL;
	f->multiple = 0;
	f->q = NULL;
	f->visited = NULL;
	f->prev = NULL;
	f->ways_num = 0;
	f->steps = -1;
	f->rooms_nb = 0;
	f->ants_num = 0;
	f->e.end_cmd = 0;
	f->e.start_cmd = 0;
	f->e.end_cmd_on = 0;
	f->e.start_cmd_on = 0;
	f->e.invalid_name = 0;
	f->e.start_room = 0;
	f->e.end_room = 0;
	f->e.room_exist = 0;
	f->e.reading_links = 0;
	f->e.end_linked = 0;
	f->e.start_linked = 0;
	f->e.error = 0;
}

int		algo(t_farm *f)
{
	errors(f);
	if (!find_ways(f))
		error_msg();
	else
	{
		display_description(f);
		pass_ants(f);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_farm	f;
	char	*line;

	param_init(&f);
	if (ac == 2)
		if (ft_strequ(av[1], "-m"))
			f.multiple = 1;
	while (get_next_line(0, &line))
	{
		write_description(&f, line);
		if (!line_analize(&f, line))
		{
			if (!f.e.error)
				error_msg();
		}
		if (f.e.error)
			return (algo(&f));
		ft_strdel(&line);
	}
	if (!(f.e.error))
		algo(&f);
	ft_printf("\n");
	return (0);
}
