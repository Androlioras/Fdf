/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_surface.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:15:55 by pribault          #+#    #+#             */
/*   Updated: 2017/06/01 13:40:48 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_root(int n)
{
	int		i;

	i = 1;
	if (n < 0)
		return (0);
	while (i * i < n)
		i++;
	if (n - (i - 1) * (i - 1) < i * i - n)
		return (i - 1);
	return (i);
}

t_point		*point_color(t_point *i, t_point p[3])
{
	i->c.r = (p[0].c.r + p[1].c.r + p[2].c.r) / 3;
	i->c.g = (p[0].c.g + p[1].c.g + p[2].c.g) / 3;
	i->c.b = (p[0].c.b + p[1].c.b + p[2].c.b) / 3;
	return (i);
}

static void	ft_surface_next(t_win *win, char *l, t_point p[3])
{
	t_point	i;
	t_point	a;
	t_point	b;
	t_point	c;

	a = p[0];
	b = p[1];
	c = p[2];
	i.x = a.x;
	while (i.x >= b.x)
	{
		i.y = ((a.y - b.y) * (i.x - b.x) / (a.x - b.x)) + b.y;
		while (i.y > ((a.y - c.y) * (i.x - c.x) / (a.x - c.x)) + c.y)
			ft_put_pixel(win, l, point_color(&i, p), -1);
		while (i.y < ((a.y - c.y) * (i.x - c.x) / (a.x - c.x)) + c.y)
			ft_put_pixel(win, l, point_color(&i, p), 1);
		ft_put_pixel(win, l, point_color(&i, p), 0);
		i.x -= 1;
	}
}

void		ft_surface(t_win *win, char *l, t_point p[3], int v)
{
	t_point	i;
	t_point	a;
	t_point	b;
	t_point	c;

	a = p[0];
	b = p[1];
	c = p[2];
	i.x = a.x;
	if (a.x == b.x || a.x == c.x)
		return ;
	while (i.x <= b.x && v == 1)
	{
		i.y = ((b.y - a.y) * (i.x - a.x) / (b.x - a.x)) + a.y;
		while (i.y > ((c.y - a.y) * (i.x - a.x) / (c.x - a.x)) + a.y)
			ft_put_pixel(win, l, point_color(&i, p), -1);
		while (i.y < ((c.y - a.y) * (i.x - a.x) / (c.x - a.x)) + a.y)
			ft_put_pixel(win, l, point_color(&i, p), 1);
		ft_put_pixel(win, l, point_color(&i, p), 0);
		i.x += 1;
	}
	if (v == -1)
		ft_surface_next(win, l, p);
}
