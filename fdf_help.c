/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:26:39 by pzubar            #+#    #+#             */
/*   Updated: 2018/02/27 15:38:34 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "mlx.h"

void	ft_create_start(t_par *params)
{
	params->y = 0;
	params->anx = -5;
	params->any = -5;
	params->anz = -5;
	params->mvx = 0;
	params->mvy = 0;
	params->mvz = 0;
	params->swilines = 1;
	params->draw = 0;
	params->mlx_ptr = mlx_init();
	params->win_ptr = mlx_new_window(params->mlx_ptr, 1600, 900, "FdF");
}

void	ft_put_instr(t_par *pr)
{
	mlx_string_put(pr->mlx_ptr, pr->win_ptr, 20, 10,\
		(int)0x5addf0, "Keys:");
	mlx_string_put(pr->mlx_ptr, pr->win_ptr, 20, 35,\
		(int)0xffffff, "Arrows: Move image | L: Switch lines");
	mlx_string_put(pr->mlx_ptr, pr->win_ptr, 20, 60,\
		(int)0x5addf0, "Numpad:");
	mlx_string_put(pr->mlx_ptr, pr->win_ptr, 20, 85,\
		(int)0xffffff, "7, 9 : Change z-axis");
	mlx_string_put(pr->mlx_ptr, pr->win_ptr, 20, 110,\
		(int)0xffffff, "-, + : Change scale");
	mlx_string_put(pr->mlx_ptr, pr->win_ptr, 20, 135,\
		(int)0xffffff, "8, 2 : Change y-axis");
	mlx_string_put(pr->mlx_ptr, pr->win_ptr, 20, 160,\
		(int)0xffffff, "4, 6 : Change x-axis");
	mlx_string_put(pr->mlx_ptr, pr->win_ptr, 20, 185,\
		(int)0x5addf0, "Mouse:");
	mlx_string_put(pr->mlx_ptr, pr->win_ptr, 20, 210,\
		(int)0xd81717, "You can draw with a help of your mouse!");
	mlx_string_put(pr->mlx_ptr, pr->win_ptr, 20, 235,\
		(int)0xffffff, "Mousewheel: Change scale");
	mlx_string_put(pr->mlx_ptr, pr->win_ptr, 20, 260,\
		(int)0xe8ea1a, "C-key cleans your window");
	mlx_string_put(pr->mlx_ptr, pr->win_ptr, 20, 285,\
		(int)0xe8ea1a, "I - O - P change type of projection");
}

int		ft_cnt_x(char *buf, int x)
{
	while (*buf)
	{
		if (*buf != ' ' && *buf != '-' &&\
			!ft_isdigit(*buf) && *buf != ',')
			return (-1);
		*buf == '-' ? buf++ : 0;
		if (ft_isdigit(*buf) && buf[1] != 'x')
			x++;
		while (ft_isdigit(*buf))
			buf++;
		if (*buf != ' ' && *buf != ',' && *buf != '\0')
			return (-1);
		if (*buf == ',' && buf++)
		{
			while (ft_isalnum(*buf))
				buf++;
			if (*buf != ' ' && *buf != '\0')
				return (-1);
		}
		if (*buf && !ft_isdigit(*buf))
			buf++;
		if (!*buf)
			break ;
	}
	return (x);
}

void	ft_buildfg(t_par *pr, t_dot **dots)
{
	t_dot	**nwdt;
	int		i;
	int		prx;
	int		pry;

	i = 0;
	prx = (pr->x / 2) * pr->sca;
	pry = (pr->y / 2) * pr->sca;
	pr->sz = pr->x * pr->y;
	if (!(nwdt = (t_dot **)malloc(sizeof(t_dot *) * pr->sz)))
		return ;
	while (i < pr->sz)
	{
		if (!(nwdt[i] = (t_dot*)malloc(sizeof(t_dot))))
			exit(-1);
		ft_move(dots, nwdt, pr, i);
		nwdt[i]->x = (nwdt[i]->x + 850 - prx) + pr->mvx;
		nwdt[i]->y = (nwdt[i]->y + 500 - pry) + pr->mvy;
		i++;
	}
	pr->nw = nwdt;
	ft_printit(nwdt, pr);
}

void	ft_tomass(t_dot **mass, char *line, int y)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (*line)
	{
		if (ft_isdigit(*line) || (*line == '-' && ft_isdigit(line[1])))
		{
			mass[i] = ft_createlem(line, x, y);
			x++;
			i++;
		}
		while (*line == '-' || ft_isdigit(*line))
			line++;
		if (*line == ',' && line++)
			while (ft_isalnum(*line))
				line++;
		while (*line == ' ' || *line == ',')
			line++;
	}
}
