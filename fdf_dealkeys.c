/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dealkeys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:14:23 by pzubar            #+#    #+#             */
/*   Updated: 2018/02/15 15:26:23 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int		ft_mouse_draw(int x, int y, t_par *pr)
{
	if (x < 0 || x > 1600 || y < 0 || y > 900)
		return (0);
	if (pr->draw == 1)
		mlx_pixel_put(pr->mlx_ptr, pr->win_ptr, x, y, (int)0xffffff);
	return (0);
}

int		ft_mouse_move(int button, int x, int y, t_par *pr)
{
	if (x < 0 || x > 1600 || y < 0 || y > 900)
		return (0);
	if (button == 1)
		pr->draw = 1;
	else if (button == 4)
	{
		mlx_clear_window(pr->mlx_ptr, pr->win_ptr);
		ft_delstruct(pr->nw, pr);
		pr->sca += 5;
		ft_buildfg(pr, pr->dt);
	}
	else if (button == 5)
	{
		mlx_clear_window(pr->mlx_ptr, pr->win_ptr);
		ft_delstruct(pr->nw, pr);
		(pr->sca - 5 > 0) ? pr->sca += -5 : 0;
		ft_buildfg(pr, pr->dt);
	}
	return (0);
}

void	ft_deal_key_1(int key, t_par *pr)
{
	if (key == 35)
	{
		pr->anx = -90;
		pr->any = 0;
		pr->anz = 0;
	}
	else if (key == 31)
	{
		pr->anx = 0;
		pr->any = 0;
		pr->anz = 0;
	}
	else if (key == 34)
	{
		pr->anx = -5;
		pr->any = -5;
		pr->anz = -5;
	}
	else if (key == 37)
		pr->swilines = (!pr->swilines) ? 1 : 0;
}

int		ft_deal_key(int key, t_par *pr)
{
	if (key == 53)
		exit(1);
	else if (key == 123 || key == 124)
		pr->mvx += (key == 123) ? -5 : 5;
	else if (key == 126 || key == 125)
		pr->mvy += (key == 126) ? -5 : 5;
	else if (key == 69)
		pr->sca += 5;
	else if (key == 78)
		(pr->sca - 5 > 0) ? pr->sca += -5 : 0;
	else if (key == 88 || key == 86)
		pr->anz += (key == 88) ? -5 : 5;
	else if (key == 84 || key == 91)
		pr->anx += (key == 84) ? 5 : -5;
	else if (key == 83 || key == 85)
		pr->any += (key == 85) ? 5 : -5;
	else if (key == 89 || key == 92)
		pr->mvz += (key == 92) ? 5 : -5;
	else
		ft_deal_key_1(key, pr);
	mlx_clear_window(pr->mlx_ptr, pr->win_ptr);
	ft_delstruct(pr->nw, pr);
	ft_buildfg(pr, pr->dt);
	return (0);
}
