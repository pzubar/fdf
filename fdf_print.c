/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:19:33 by pzubar            #+#    #+#             */
/*   Updated: 2018/02/15 12:19:35 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

#define DEFCOL (long)0x12B212

int		ft_forcexit(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

void	ft_delstruct(t_dot **strct, t_par *pr)
{
	int i;

	i = 0;
	while (i != pr->sz + 1)
	{
		free(strct[i]);
		i++;
	}
	free(strct);
}

void	ft_writeline(t_dot **dt, t_par *pr, int i)
{
	pr->nx = dt[0]->x;
	pr->ny = dt[0]->y;
	pr->dx = ft_abs(dt[i]->x - dt[0]->x);
	pr->sx = dt[0]->x < dt[i]->x ? 1 : -1;
	pr->dy = -ft_abs(dt[i]->y - dt[0]->y);
	pr->sy = dt[0]->y < dt[i]->y ? 1 : -1;
	pr->err = pr->dx + pr->dy;
	while (1)
	{
		mlx_pixel_put(pr->mlx_ptr, pr->win_ptr, pr->nx, pr->ny, (dt[0]->color\
			== DEFCOL) ? (int)dt[i]->color : (int)dt[0]->color);
		if (pr->nx == dt[i]->x && pr->ny == dt[i]->y)
			break ;
		pr->er2 = 2 * pr->err;
		if (pr->er2 >= pr->dy)
		{
			pr->err += pr->dy;
			pr->nx += pr->sx;
		}
		if (pr->er2 <= pr->dx)
		{
			pr->err += pr->dx;
			pr->ny += pr->sy;
		}
	}
}

int		ft_mouse_del(int button, int x, int y, t_par *par)
{
	if (x < 0 || x > 1600 || y < 0 || y > 900)
		return (0);
	if (button == 1)
		par->draw = 0;
	return (0);
}

void	ft_printit(t_dot **dots, t_par *pr)
{
	int i;

	i = 0;
	ft_put_instr(pr);
	if (pr->sz-- == 1 && ++i)
		mlx_pixel_put(pr->mlx_ptr, pr->win_ptr, dots[0]->x,\
			dots[0]->y, (int)dots[0]->color);
	while (i < pr->sz)
	{
		if (pr->swilines && i < pr->sz && ((i + 1) % pr->x))
			ft_writeline(&dots[i], pr, 1);
		if (pr->swilines && i + pr->x < pr->sz + 1)
			ft_writeline(&dots[i], pr, pr->x);
		else
			mlx_pixel_put(pr->mlx_ptr, pr->win_ptr, dots[i]->x,\
				dots[i]->y, (int)dots[i]->color);
		i++;
	}
	mlx_hook(pr->win_ptr, 2, 5, ft_deal_key, pr);
	mlx_hook(pr->win_ptr, 17, 1L << 17, ft_forcexit, (void *)0);
	mlx_hook(pr->win_ptr, 4, 5, ft_mouse_move, pr);
	mlx_hook(pr->win_ptr, 5, 5, ft_mouse_del, pr);
	mlx_hook(pr->win_ptr, 6, 1L << 6, ft_mouse_draw, pr);
	mlx_loop(pr->mlx_ptr);
}
