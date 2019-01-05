/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:05:39 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/04 20:05:41 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int				i;
	char			*new;

	if (!s)
		return (0);
	i = 0;
	if (start > ft_strlen(s) || !s)
		return (0);
	new = (char*)malloc(len + 1);
	if (!new)
		return (NULL);
	ft_strncpy(new, &s[start], len);
	new[len] = '\0';
	return (new);
}
