/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words_chr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:23:32 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/06 11:23:34 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_wordschr(char const *str, char c)
{
	int i;
	int sum;
	int count;

	i = 0;
	sum = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != c && str[i])
		{
			i++;
			sum = 1;
		}
		if (str[i] == c || str[i] == '\0')
		{
			count = count + ((sum == 1) ? 1 : 0);
			sum = 0;
			i++;
		}
	}
	return (count);
}
