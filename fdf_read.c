/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:42:04 by pzubar            #+#    #+#             */
/*   Updated: 2018/02/11 17:42:13 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "mlx.h"

#define DEFCOL (long)0x12B212

int		ft_preread(char *file)
{
	char	*line;
	int		x;
	int		fd;

	line = NULL;
	fd = open(file, O_RDONLY);
	if ((fd < 0 || read(fd, line, 0) < 0))
		return (-1);
	x = 0;
	while (get_next_line(fd, &line))
	{
		if ((x = ft_cnt_x(line, x)) < 0)
		{
			ft_putendl_fd("Invalid map", 2);
			return (-1);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return (x);
}

t_dot	*ft_createlem(char *line, int x, int y)
{
	t_dot	*dt;

	dt = (t_dot*)malloc(sizeof(t_dot));
	dt->x = x;
	dt->y = y;
	dt->z = ft_atoi(line);
	line++;
	while (ft_isdigit(*line))
		line++;
	if (*line == ',')
	{
		line += 3;
		dt->color = ft_atoi_base(line, 16);
	}
	else
		dt->color = DEFCOL;
	return (dt);
}

void	ft_move(t_dot **dots, t_dot **new, t_par *pr, int i)
{
	int x;
	int y;
	int bux;

	new[i]->x = (dots[i]->x * pr->sca);
	new[i]->y = (dots[i]->y * pr->sca);
	new[i]->z = pr->sca * ((dots[i]->z) ? (dots[i]->z + pr->mvz) : dots[i]->z);
	new[i]->color = dots[i]->color;
	if (dots[i]->color == DEFCOL && new[i]->z != 0)
		new[i]->color = (new[i]->z + pr->mvz < 0) ? 0x4319FF : 0xB25309;
	x = new[i]->x;
	y = new[i]->y;
	new[i]->y = (new[i]->y * cos(pr->anx * M_PI / 180)) +\
	(new[i]->z * sin(pr->anx * M_PI / 180));
	new[i]->z = (new[i]->z * cos(pr->anx * M_PI / 180)) -\
	(new[i]->y * sin(pr->anx * M_PI / 180));
	bux = (x * cos(pr->any * M_PI / 180)) - (new[i]->z *\
		sin(pr->any * M_PI / 180));
	new[i]->z = (new[i]->z * cos(pr->any * M_PI / 180)) +\
	(x * sin(pr->any * M_PI / 180));
	new[i]->x = (bux * cos(pr->anz * M_PI / 180)) +\
	(new[i]->y * sin(pr->anz * M_PI / 180));
	new[i]->y = (new[i]->y * cos(pr->anz * M_PI / 180))\
	- (bux * sin(pr->anz * M_PI / 180));
}

int		ft_readfile(int fd, t_par *pr, char *line, t_dot **dots)
{
	int		i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		if (pr->y == 0)
		{
			if (!(pr->x = ft_cnt_x(line, 0)))
				ft_strdel(&line);
		}
		if (ft_cnt_x(line, 0) != pr->x || !line)
		{
			ft_strdel(&line);
			return (-1);
		}
		ft_tomass(&(dots[i]), line, pr->y);
		pr->y++;
		i = i + pr->x;
		(line) ? ft_strdel(&line) : line;
	}
	pr->sca = (pr->x < pr->y) ? 700 / pr->y : 800 / pr->x;
	pr->dt = dots;
	ft_buildfg(pr, dots);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_par	*params;
	t_dot	**dots;

	if (argc == 2)
	{
		if (!(params = (t_par*)malloc(sizeof(t_par))))
			return (-1);
		if ((params->sz = ft_preread(argv[1])) <= 0)
			return (-1);
		if (!(dots = (t_dot **)malloc(sizeof(t_dot*) * (params->sz))))
			return (-1);
		fd = open(argv[1], O_RDONLY);
		ft_create_start(params);
		if (ft_readfile(fd, params, NULL, dots) == -1)
		{
			ft_putendl_fd("Error", 2);
			return (-1);
		}
		ft_delstruct(dots, params);
		free(params);
	}
	return (0);
}
