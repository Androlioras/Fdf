/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:48:31 by pribault          #+#    #+#             */
/*   Updated: 2017/06/01 11:01:22 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** includes
*/

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

/*
** macros
*/

# define COLOR 1
# define S 0.1

/*
** structures
*/

typedef unsigned char	t_c;

typedef struct	s_map
{
	int			**map;
	int			h;
	int			w;
}				t_map;

typedef struct	s_flag
{
	double		s;
	double		c;
	int			h;
	int			o;
}				t_flag;

typedef struct	s_img
{
	void		*img;
	char		*l;
	int			b;
	int			s;
	int			e;
}				t_img;

typedef struct	s_win
{
	t_flag		f;
	t_map		*map;
	t_img		i;
	void		*mlx;
	void		*win;
	char		*title;
	int			h;
	int			w;
}				t_win;

typedef struct	s_color
{
	t_c		r;
	t_c		g;
	t_c		b;
}				t_color;

typedef struct	s_point
{
	t_color		c;
	int			x;
	int			y;
}				t_point;

/*
** protypes
*/

int				ft_error(char *str);
void			ft_log(char *str);
t_win			*flags(int argc, char **argv);

void			ft_print_map(t_win *win);
void			ft_draw(t_win *win);

t_map			*create_map(char *str);

int				ft_key_hook(int k, t_win *win);
int				ft_mouse_hook(int k, int x, int y, t_win *win);

void			ft_rotate_left(t_map *array);
void			ft_rotate_right(t_map *array);

t_point			ft_iso(t_win *win, int i, int j);

void			ft_put_pixel(t_win *win, char *l, t_point *a, int value);
void			ft_surface(t_win *win, char *line, t_point p[3], int v);

int				ft_abs(int n);
t_point			ft_wire_color(t_point a, double m[3], t_point i);

int				ctoi(t_color c);
t_color			itoc(int c);

#endif
