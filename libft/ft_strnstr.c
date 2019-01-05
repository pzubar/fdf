/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:42:55 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/01 19:32:20 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t i;
	size_t n;

	i = 0;
	n = 0;
	if (ft_strlen(lit) == 0)
		return ((char*)big);
	if (big[i] == '\0')
	{
		return (NULL);
	}
	while (big[i] != '\0')
	{
		n = 0;
		while (big[i + n] == lit[n] && i + n < len)
		{
			n++;
			if (lit[n] == '\0')
				return ((char*)big + i);
		}
		i++;
	}
	return (NULL);
}
