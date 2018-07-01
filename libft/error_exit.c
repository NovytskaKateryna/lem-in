/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:50:10 by knovytsk          #+#    #+#             */
/*   Updated: 2018/06/04 16:03:34 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_exit(const char *msg)
{
	ft_putendl(msg);
	exit(1);
}
