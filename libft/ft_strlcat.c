/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:29:29 by pzubar            #+#    #+#             */
/*   Updated: 2017/10/30 16:29:31 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (dst[i])
		i++;
	if (ft_strlen(dst) < len)
	{
		len = len - i;
		while (*src && len != 1)
		{
			dst[i] = *src;
			i++;
			src++;
			len--;
		}
		dst[i] = '\0';
		return (ft_strlen(src) + i);
	}
	return (ft_strlen(src) + len);
}
