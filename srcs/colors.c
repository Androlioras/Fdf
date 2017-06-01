/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:05:40 by pribault          #+#    #+#             */
/*   Updated: 2016/11/29 13:26:50 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_wire_color(t_point a, double m[3], t_point i)
{
	i.c.r = a.c.r + m[0] * (i.x + i.y - a.x - a.y);
	i.c.g = a.c.g + m[1] * (i.x + i.y - a.x - a.y);
	i.c.b = a.c.b + m[2] * (i.x + i.y - a.x - a.y);
	return (i);
}

t_color	itoc(int c)
{
	t_color	color;

	color.r = c / 65536;
	color.g = (c - color.r * 65536) / 256;
	color.b = (c - (color.r * 65536) - (color.g * 256));
	return (color);
}

int		ctoi(t_color color)
{
	int		c;

	c = color.r * 65536 + color.g * 256 + color.b;
	return (c);
}
