/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comp_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:50:10 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:02:20 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_comp_num(char **split, int num)
{
	int n;

	n = 0;
	if (!split)
		return (0);
	while (split[n])
		n++;
	if (n == num)
		return (1);
	return (0);
}
