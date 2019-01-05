/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:43:32 by pzubar            #+#    #+#             */
/*   Updated: 2017/10/27 13:26:46 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;

	tmp = dst;
	if (dst > src)
	{
		while (n--)
		{
			tmp[n] = ((unsigned char*)src)[n];
		}
	}
	else
	{
		while (n--)
		{
			*tmp++ = *((unsigned char*)src++);
		}
	}
	return (dst);
}
