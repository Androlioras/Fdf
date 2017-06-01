/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:01:23 by pribault          #+#    #+#             */
/*   Updated: 2016/11/29 18:28:07 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	*flags(int argc, char **argv)
{
	t_win	*win;
	int		i;

	i = 2;
	if (!(win = (t_win*)malloc(sizeof(t_win))))
		return (NULL);
	win->w = 1440;
	win->h = 720;
	win->title = ft_strdup("FdF");
	while (i < argc)
	{
		if (i + 2 < argc && ft_strcmp(argv[i], "-size") == 0)
		{
			win->w = ft_atoi(argv[i + 1]);
			win->h = ft_atoi(argv[i + 2]);
			i += 3;
		}
		if (i + 1 < argc && ft_strcmp(argv[i], "-title") == 0)
		{
			win->title = ft_strdup(argv[i + 1]);
			i++;
		}
		i++;
	}
	return (win);
}
