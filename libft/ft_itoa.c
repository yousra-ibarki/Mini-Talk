/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:41:26 by yoibarki          #+#    #+#             */
/*   Updated: 2022/10/28 03:26:13 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int number)
{
	long	i;
	long	c;

	i = 1;
	c = 0;
	if (number < 0)
	{
		c++;
		number = -number;
	}
	if (number < 10)
	{
		c++;
		return (c);
	}
	while (i <= number)
	{
		i *= 10;
		c++;
	}
	return (c);
}

static char	*ifneg(char *ptr, int nbr, int len)
{
	ptr[0] = '-';
	nbr = -nbr;
	if (nbr >= 10)
	{
		while (--len > 0)
		{
			ptr[len] = (nbr % 10) + '0';
			nbr /= 10;
		}
	}
	else
		ptr[1] = nbr + '0';
	return (ptr);
}

static char	*ft_tochar(char *ptr, int nbr, int len)
{
	long	i;

	i = 0;
	ptr[len] = '\0';
	if (nbr < 0)
		return (ifneg(ptr, nbr, len));
	if (nbr >= 10)
	{
		while (--len >= 0)
		{
			ptr[len] = (nbr % 10) + '0';
			nbr /= 10;
		}
	}
	else
		ptr[--len] = (nbr % 10) + '0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	long	i;
	int		len;
	char	*ptr;

	i = 0;
	if (n == -2147483648)
		return (ptr = ft_strdup("-2147483648"));
	len = ft_count(n);
	ptr = malloc((sizeof(char) * len + 1));
	if (!ptr)
		return (NULL);
	ft_tochar(ptr, n, len);
	return (ptr);
}
