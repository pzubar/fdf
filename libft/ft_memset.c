/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:22:52 by pzubar            #+#    #+#             */
/*   Updated: 2017/10/26 18:22:54 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	int		i;

	i = 0;
	if (n != 0)
	{
		while ((size_t)n > 0)
		{
			((unsigned char*)dst)[i] = (char)c;
			i++;
			n--;
		}
	}
	return ((unsigned char*)dst);
}
