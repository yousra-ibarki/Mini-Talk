/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:18:20 by yoibarki          #+#    #+#             */
/*   Updated: 2022/11/19 15:18:24 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counthex(unsigned int h)
{
	int	i;

	i = 0;
	if (!h)
		return (1);
	while (h)
	{
		h /= 16;
		i++;
	}
	return (i);
}

static void	ft_upplow(unsigned int h, char type)
{
	int	out;

	out = 0;
	if (type == 'x')
	{
		out += h - 10 + 97;
		write(1, &out, 1);
	}
	else if (type == 'X')
	{
		out += h - 10 + 65;
		write(1, &out, 1);
	}
}

int	ft_printhex(unsigned int h, char type)
{
	int	len;
	int	out;

	len = ft_counthex(h);
	out = 0;
	if (h >= 16)
	{
		ft_printhex(h / 16, type);
		ft_printhex(h % 16, type);
	}
	else if (h < 10)
	{
		out += h + '0';
		write(1, &out, 1);
	}
	else
		ft_upplow(h, type);
	return (len);
}
