/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:47:18 by pribault          #+#    #+#             */
/*   Updated: 2017/06/01 13:41:26 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(char *str)
{
	ft_log(ft_strjoin("[error] ", str));
	return (-1);
}

void	clear_log(void)
{
	int		fd;

	fd = open("log", O_TRUNC);
	if (fd)
		close(fd);
	fd = open("log", O_CREAT, 0666);
	if (fd)
		close(fd);
}

void	ft_log(char *str)
{
	int		fd;

	fd = open("log", O_APPEND | O_WRONLY);
	if (fd < 0)
		return ;
	ft_putstr_fd("[log] ", fd);
	ft_putendl_fd(str, fd);
	close(fd);
}

void	print_logs(t_win *win)
{
	ft_log(ft_strjoin("height set to: ", ft_itoa(win->h)));
	ft_log(ft_strjoin("width set to: ", ft_itoa(win->w)));
	ft_log(ft_strjoin("title set to: ", win->title));
	ft_log("file opened and map filled");
	ft_putendl(" ----- CONTROLS -----");
	ft_putendl("");
	ft_putendl(" +  and  -     to modify color");
	ft_putendl("<-  and  ->    to rotate the image");
	ft_putendl("up  and  down  to zoom");
	ft_putendl("scroll to modify altitude");
	ft_putendl("");
	ft_putendl("       _enjoy!_");
}

int		main(int argc, char **argv)
{
	t_win	*win;
	int		i;

	clear_log();
	if (argc >= 2)
	{
		i = 0;
		if (!(win = flags(argc, argv)))
			return (ft_error("can't initialize window."));
		if (!(win->map = create_map(argv[1])))
			return (ft_error("array can't be filled."));
		win->f.c = 2;
		win->f.s = 1;
		win->f.h = 0;
		win->f.o = 0;
		print_logs(win);
		if (!(win->mlx = mlx_init()))
			return (ft_error("can't initialize mlx."));
		if (!(win->win = mlx_new_window(win->mlx, win->w, win->h, win->title)))
			return (ft_error("can't open window."));
		ft_draw(win);
	}
	else
		return (ft_error("./fdf <filename> -<flags>"));
	return (1);
}
