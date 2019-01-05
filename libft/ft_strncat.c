/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:05:48 by pzubar            #+#    #+#             */
/*   Updated: 2017/10/30 16:05:51 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	int i;
	int n;
	int a;

	a = 0;
	i = 0;
	n = 0;
	while (dst[i])
		i++;
	while (src[n] && len != 0)
	{
		dst[i] = src[n];
		i++;
		n++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}
