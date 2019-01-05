/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:01:53 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/06 18:18:37 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*new;
	int		i;
	int		sign;
	int		nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = n;
	nb = n;
	i = 1;
	n = ((sign < 0) ? -n : n);
	while ((nb = (nb / 10)) != 0)
		i++;
	i = ((sign < 0) ? (i + 1) : i);
	if (!(new = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	new[i] = '\0';
	while (i--)
	{
		new[i] = n % 10 + '0';
		n = n / 10;
	}
	if (sign < 0)
		new[0] = '-';
	return (new);
}
