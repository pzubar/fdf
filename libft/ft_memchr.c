/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:57:36 by pzubar            #+#    #+#             */
/*   Updated: 2017/10/27 21:57:44 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *pointer;

	pointer = ((unsigned char *)s);
	if (n != 0)
	{
		while (n != 0)
		{
			if (*pointer++ == (unsigned char)c)
			{
				return (void *)(pointer - 1);
			}
			n--;
		}
	}
	return (NULL);
}
