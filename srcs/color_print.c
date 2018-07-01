/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:31:44 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:34:40 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	color_print2(int color)
{
	if (color == 9)
		write(1, LIGHT_RED, 8);
	else if (color == 10)
		write(1, LIGHT_GREEN, 8);
	else if (color == 11)
		write(1, YELLOW, 8);
	else if (color == 12)
		write(1, LIGHT_BLUE, 8);
	else if (color == 13)
		write(1, LIGHT_PURPLE, 8);
	else if (color == 14)
		write(1, LIGHT_CYAN, 8);
	else if (color == 15)
		write(1, WHITE, 8);
}

void	set_color(int color)
{
	if (color == 1)
		write(1, RED, 8);
	else if (color == 2)
		write(1, GREEN, 8);
	else if (color == 3)
		write(1, BROWN, 8);
	else if (color == 4)
		write(1, BLUE, 8);
	else if (color == 5)
		write(1, PURPLE, 8);
	else if (color == 6)
		write(1, CYAN, 8);
	else if (color == 7)
		write(1, LIGHT_GRAY, 8);
	else if (color == 8)
		write(1, DARK_GRAY, 8);
	color_print2(color);
}

void	color_print(int ant_num, char *room, int color)
{
	set_color(color);
	ft_printf("L%i-%s ", ant_num, room);
	write(1, EOC, 5);
}

void	color_array(t_farm *f)
{
	t_path	*tmp;
	int		i;
	int		j;

	f->ant_color = (int*)malloc(sizeof(int) * (f->ants_num + 1));
	j = 1;
	i = 0;
	while (++i <= f->ants_num)
	{
		f->ant_color[i] = j++;
		if (j == 16)
			j = 1;
	}
	tmp = f->ways;
	j = 1;
	while (tmp)
	{
		tmp->color = j++;
		if (j == 16)
			j = 1;
		tmp = tmp->next;
	}
}

void	print_paths(t_farm *f)
{
	t_path	*tmp;
	int		way;
	int		i;

	tmp = f->ways;
	way = -1;
	write(1, WHITE, 8);
	ft_printf("Turns: %i\n\n", f->turns - 1);
	while (++way < f->ways_num)
	{
		i = -1;
		if (f->ways_num > 1)
			set_color(tmp->color);
		while (++i < tmp->path_nodes)
		{
			ft_printf("%s", get_room_name(f, tmp->path[i]));
			if (i != tmp->path_nodes - 1)
				ft_printf("->");
		}
		ft_printf("\n");
		if (f->ways_num > 1)
			write(1, EOC, 5);
		tmp = tmp->next;
	}
	write(1, EOC"\n", 6);
}
