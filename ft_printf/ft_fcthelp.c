/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fcthelp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:16:33 by yoibarki          #+#    #+#             */
/*   Updated: 2022/11/19 15:16:35 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_prints(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_prints("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnb(int nb)
{
	int		i;
	char	*n;

	i = 0;
	n = ft_itoa(nb);
	while (n[i])
	{
		write(1, &n[i], 1);
		i++;
	}
	free(n);
	return (i);
}

int	ft_count(unsigned int h)
{
	int	i;

	i = 0;
	if (!h)
		return (1);
	while (h)
	{
		h /= 10;
		i++;
	}
	return (i);
}
