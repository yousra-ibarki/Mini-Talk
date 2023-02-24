/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:18:32 by yoibarki          #+#    #+#             */
/*   Updated: 2022/11/19 15:18:35 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printunsigned(unsigned int nb)
{
	int		len;
	char	*nbr;
	int		i;

	len = 0;
	len = ft_count(nb);
	i = 0;
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	while (i < len)
	{
		nbr[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	while (i > 0)
	{
		write(1, &nbr[i - 1], 1);
		i--;
	}
	free(nbr);
	return (len);
}
