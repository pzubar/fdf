/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:23:44 by pzubar            #+#    #+#             */
/*   Updated: 2017/10/27 12:23:46 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sorc;

	i = 0;
	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	if (n)
	{
		while (i < n)
		{
			if ((*dest = *sorc) == (unsigned char)c)
				return (dst + i + 1);
			*dest = *sorc;
			dest++;
			sorc++;
			i++;
		}
	}
	return (0);
}
