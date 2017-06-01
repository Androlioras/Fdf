/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:48:04 by pribault          #+#    #+#             */
/*   Updated: 2016/11/25 19:02:13 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_left(t_map *array)
{
	int		**result;
	int		h;
	int		w;
	int		i;
	int		j;

	h = array->h;
	w = array->w;
	result = (int**)ft_alloc_array(w, h, sizeof(int));
	i = 0;
	while (i < w)
	{
		j = 0;
		h = array->h;
		while (--h >= 0)
		{
			result[i][j] = array->map[h][i];
			j++;
		}
		i++;
	}
	ft_free_array((void**)array->map, j);
	array->map = result;
	array->h = i;
	array->w = j;
}

void	ft_rotate_right(t_map *array)
{
	int		**result;
	int		h;
	int		w;
	int		i;
	int		j;

	h = array->h;
	w = array->w;
	result = (int**)ft_alloc_array(w, h, sizeof(int));
	i = 0;
	while (--w >= 0)
	{
		j = 0;
		while (j < h)
		{
			result[i][j] = array->map[j][w];
			j++;
		}
		i++;
	}
	ft_free_array((void**)array->map, j);
	array->map = result;
	array->h = i;
	array->w = j;
}
