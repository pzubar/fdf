/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:05:49 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/06 11:05:51 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SZ sizeof(char*)

static char	**ft_componator(char const *s, char **new, char c, int i)
{
	int j;
	int k;

	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			if (!(new[j] = (char*)malloc(SZ * (ft_strlenichr(s, i, c) + 1))))
			{
				while (--j)
					free(new[j]);
				return (NULL);
			}
			while (s[i] != c && s[i])
				new[j][k++] = s[i++];
			new[j++][k] = '\0';
		}
	}
	new[j] = NULL;
	return (new);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**new;

	i = 0;
	if (!s)
		return (NULL);
	if (!(new = (char**)malloc(SZ * (ft_count_wordschr(s, c)) + 1)))
		return (NULL);
	new = ft_componator(s, new, c, i);
	if (!new)
		free(new);
	return (new);
}
