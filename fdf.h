/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:15:01 by pzubar            #+#    #+#             */
/*   Updated: 2018/02/11 18:15:03 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include "libft/libft.h"

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	long			color;
}					t_dot;

typedef struct		s_par
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				anx;
	int				any;
	int				anz;
	int				sca;
	int				x;
	int				y;
	int				sz;
	int				nx;
	int				ny;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				er2;
	int				mvx;
	int				mvy;
	int				mvz;
	char			swilines;
	int				draw;
	t_dot			**dt;
	t_dot			**nw;
}					t_par;

void				ft_printit(t_dot **dots, t_par *pr);
int					ft_cnt_x(char *buf, int x);
void				ft_rebuild(t_par *pr, t_dot **old);
t_dot				*ft_createlem(char *line, int x, int y);
void				ft_move(t_dot **dots, t_dot **new, t_par *pr, int i);
void				ft_tomass(t_dot **mass, char *line, int y);
void				ft_buildfg(t_par *pr, t_dot **dots);
int					ft_deal_key(int key, t_par *pr);
void				ft_delstruct(t_dot **strct, t_par *pr);
void				ft_put_instr(t_par *pr);
void				ft_create_start(t_par *params);
int					ft_mouse_move(int button, int x, int y, t_par *pr);
int					ft_mouse_draw(int x, int y, t_par *pr);

#endif
