/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:55:05 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/04 19:36:06 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	new = ft_strnew(ft_strlen(s));
	if (new)
	{
		while (*s)
		{
			new[i] = f(i, *s);
			s++;
			i++;
		}
		return (new);
	}
	return (NULL);
}
