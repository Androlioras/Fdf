/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:11:23 by pribault          #+#    #+#             */
/*   Updated: 2016/11/29 15:52:17 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			dtoi(double n)
{
	int		i;

	i = n;
	if (n - i < 0.1)
		return (i);
	return (-1);
}

int			ft_abs(int n)
{
	return ((n < 0) ? -n : n);
}

t_point		ft_iso(t_win *win, int i, int j)
{
	t_point		p;
	double		h[2];
	int			x;
	int			y;
	int			c;

	i = (i < 0) ? 0 : i;
	j = (j < 0) ? 0 : j;
	c = win->map->map[i][j] * win->f.c;
	h[1] = win->w * (win->h - win->f.h) / win->h;
	h[0] = h[1] / 2;
	x = win->map->w;
	y = win->map->h;
	p.x = win->f.h + h[1] * (i + j) / (x + y);
	p.y = win->f.h / 2 + h[0] * (x + i - j) / (x + y) - c * win->f.s / win->f.c;
	p.x = (p.x >= win->w) ? win->w - 1 : p.x;
	p.x = (p.x < 0) ? 0 : p.x;
	p.y = (p.y >= win->h) ? win->h - 1 : p.y;
	p.y = (p.y < 0) ? 0 : p.y;
	p.c.r = (c < 0) ? ft_abs(255 - c) : 255;
	p.c.b = (c >= 0) ? ft_abs(255 - c) : 255;
	p.c.g = ft_abs(255 - p.c.r - p.c.b);
	return (p);
}
