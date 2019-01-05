/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 21:27:51 by pzubar            #+#    #+#             */
/*   Updated: 2018/02/22 21:27:53 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_checkbase(char c)
{
	int		n;

	if (c >= '0' && c <= '9')
		n = c - '0';
	else if (c >= 'a' && c <= 'z')
		n = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		n = c - 'A' + 10;
	else
		n = -1;
	return (n);
}

int		ft_atoi_base(const char *str, int base)
{
	int		n;
	int		sign;
	int		pos;

	n = 0;
	sign = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	pos = ft_checkbase(*str);
	while (pos >= 0 && pos < base)
	{
		n = n * base + pos;
		str++;
		pos = ft_checkbase(*str);
	}
	return (sign ? -n : n);
}
