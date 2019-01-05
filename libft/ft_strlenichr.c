/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenichr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:38:24 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/06 11:38:26 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlenichr(char const *str, int i, char c)
{
	int count;

	count = 0;
	if (!str)
		return (0);
	while (str[i] != c && str[i] != c && str[i] != c && str[i])
	{
		count++;
		i++;
	}
	return (count);
}
