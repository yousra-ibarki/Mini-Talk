/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:17:26 by yoibarki          #+#    #+#             */
/*   Updated: 2022/11/19 15:17:34 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ftt_count(unsigned long long h)
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

static void	ft_check(unsigned long long p)
{
	int	out;

	out = 0;
	if (p >= 16)
	{
		ft_check(p / 16);
		ft_check(p % 16);
	}
	else if (p < 10)
	{
		out += p + '0';
		write(1, &out, 1);
	}
	else
	{
		out += p - 10 + 97;
		write(1, &out, 1);
	}
}

int	ft_printp(unsigned long long p)
{
	int	len;
	int	out;

	len = 2;
	out = 0;
	write(1, "0x", 2);
	if (p == 0)
	{
		len += ft_putchar('0');
		return (len);
	}
	else
		ft_check(p);
	return (ftt_count(p) + len);
}
