/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 21:30:32 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/04 21:30:39 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		pos;
	char	*new;

	if (!s)
		return (NULL);
	i = (ft_strlen(s));
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	pos = -1;
	while (s[++pos] == ' ' || s[pos] == '\n' || s[pos] == '\t')
		i--;
	i = ((i <= 0) ? 0 : i);
	new = (char*)malloc(sizeof(char) * i + 1);
	if (!new)
		return (NULL);
	s = s + pos;
	pos = -1;
	while (++pos < i)
		new[pos] = *s++;
	new[pos] = '\0';
	return (new);
}
