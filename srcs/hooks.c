/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:54:58 by pribault          #+#    #+#             */
/*   Updated: 2016/11/28 17:38:34 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key_hook(int k, t_win *win)
{
	if (k == 125 || k == 126)
		win->f.h += (k == 125) ? 64 : -64;
	if (k == 69 || k == 78)
		win->f.c += (k == 69) ? COLOR : -COLOR;
	if (k == 124)
		ft_rotate_right(win->map);
	if (k == 123)
		ft_rotate_left(win->map);
	if (k == 53)
		exit(0);
	else
		ft_log(ft_strjoin("key pressed: ", ft_itoa(k)));
	ft_print_map(win);
	return (1);
}

int		ft_mouse_hook(int k, int x, int y, t_win *win)
{
	x++;
	y++;
	if (k == 1)
		win->f.o = (win->f.o == 0) ? 1 : 0;
	if (k == 4 || k == 5)
		win->f.s += (k == 5) ? S : -S;
	ft_print_map(win);
	ft_log(ft_strjoin("mouse key pressed: ", ft_itoa(k)));
	return (1);
}
