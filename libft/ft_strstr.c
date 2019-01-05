/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:53:04 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/01 19:33:15 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int n;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	if (big[i] == '\0')
	{
		return (NULL);
	}
	while (big[i] != '\0')
	{
		n = 0;
		while (big[i + n] == little[n])
		{
			n++;
			if (little[n] == '\0')
				return ((char*)big + i);
		}
		i++;
	}
	return (0);
}
