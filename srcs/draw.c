/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:25:01 by pribault          #+#    #+#             */
/*   Updated: 2017/06/01 13:51:14 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_put_pixel(t_win *win, char *l, t_point *a, int value)
{
	l[a->y * win->i.s + a->x * win->i.b / 8 + 2] = a->c.r;
	l[a->y * win->i.s + a->x * win->i.b / 8 + 1] = a->c.g;
	l[a->y * win->i.s + a->x * win->i.b / 8] = a->c.b;
	a->y += value;
}

void	ft_wire(t_win *win, char *l, t_point a, t_point b)
{
	double	m[3];
	t_point	i;

	i.x = b.x + b.y - a.x - a.y;
	m[0] = (b.x + b.y != a.x + a.y) ? (b.c.r - a.c.r) / i.x : 0;
	m[1] = (b.x + b.y != a.x + a.y) ? (b.c.g - a.c.g) / i.x : 0;
	m[2] = (b.x + b.y != a.x + a.y) ? (b.c.b - a.c.b) / i.x : 0;
	i = a;
	while (i.x < b.x)
	{
		i = ft_wire_color(a, m, i);
		i.y = ((b.y - a.y) * (i.x - a.x) / (b.x - a.x)) + a.y;
		while (i.y < ((b.y - a.y) * (i.x + 1 - a.x) / (b.x - a.x)) + a.y)
			ft_put_pixel(win, l, &i, 1);
		while (i.y > ((b.y - a.y) * (i.x + 1 - a.x) / (b.x - a.x)) + a.y)
			ft_put_pixel(win, l, &i, -1);
		ft_put_pixel(win, l, &i, 0);
		(i.x)++;
	}
	i = a;
	while (i.x == b.x && i.y != b.y)
	{
		i = ft_wire_color(a, m, i);
		ft_put_pixel(win, l, &i, (i.y < b.y) ? 1 : -1);
	}
}

void	ft_print(t_win *win, char *l, int i, int j)
{
	t_point	p[3];
	t_point	a;
	t_point	b;
	t_point	c;
	t_point	d;

	a = ft_iso(win, i - 1, j - 1);
	b = ft_iso(win, i - 1, j);
	c = ft_iso(win, i, j - 1);
	d = ft_iso(win, i, j);
	if (win->f.o == 1)
	{
		ft_wire(win, l, b, c);
		ft_wire(win, l, c, d);
		ft_wire(win, l, b, d);
	}
	else
	{
		p[0] = a;
		p[1] = c;
		p[2] = b;
		ft_surface(win, l, p, 1);
		p[0] = d;
		ft_surface(win, l, p, -1);
	}
}

void	ft_print_map(t_win *win)
{
	int		i[2];

	if (win->h > win->w / 2)
		win->h = win->w / 2;
	else
		win->w = win->h * 2;
	mlx_clear_window(win->mlx, win->win);
	ft_bzero(win->i.l, win->h * win->i.s);
	i[0] = 0;
	while (i[0] < win->map->h)
	{
		i[1] = win->map->w - 1;
		while (i[1] >= 0)
		{
			ft_print(win, win->i.l, i[0], i[1]);
			i[1]--;
		}
		i[0]++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->i.img, 0, 0);
}

void	ft_draw(t_win *win)
{
	win->i.img = mlx_new_image(win->mlx, win->w, win->h);
	win->i.l = mlx_get_data_addr(win->i.img, &(win->i.b), &(win->i.s),
	&(win->i.e));
	ft_print_map(win);
	mlx_key_hook(win->win, ft_key_hook, win);
	mlx_mouse_hook(win->win, ft_mouse_hook, win);
	mlx_loop(win->mlx);
}
