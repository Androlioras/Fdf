/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:27:09 by pribault          #+#    #+#             */
/*   Updated: 2016/12/07 16:22:15 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*del_and_exit(t_map *map, int len)
{
	if (map->map)
		ft_free_array((void**)map->map, len);
	free(map);
	return (NULL);
}

t_map			*fill_map(char *str, int len, int width)
{
	t_map	*map;
	char	**array;
	char	*line;
	int		i[3];

	i[0] = 0;
	i[2] = open(str, O_RDONLY);
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (del_and_exit(map, len));
	if (!(map->map = (int**)ft_alloc_array(len, width, sizeof(int))))
		return (del_and_exit(map, len));
	while (ft_get_next_line(i[2], &line))
	{
		i[1] = 0;
		array = ft_strsplit(line, ' ');
		if (ft_arraylen(array) != width)
			return (del_and_exit(map, len));
		while (array[i[1]])
			map->map[i[0]][i[1]++] = ft_atoi(array[i[1]]);
		free(array);
		i[0]++;
	}
	close(i[2]);
	return (map);
}

t_map			*create_map(char *str)
{
	t_map	*map;
	char	*line;
	int		width;
	int		len;
	int		fd;

	if ((fd = open(str, O_RDONLY)) <= 0 || read(fd, &len, 0) == -1)
		return (NULL);
	len = 0;
	while (ft_get_next_line(fd, &line))
	{
		width = ft_arraylen(ft_strsplit(line, ' '));
		len++;
	}
	close(fd);
	map = fill_map(str, len, width);
	if (!map)
		return (NULL);
	map->h = len;
	map->w = width;
	return (map);
}
