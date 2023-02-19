/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:00:06 by yoibarki          #+#    #+#             */
/*   Updated: 2022/10/24 11:22:39 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	checkintmaxmin(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n == 2147483647)
	{
		write(fd, "2147483647", 10);
		return ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	out;

	if (n == -2147483648 || n == 2147483647)
	{
		checkintmaxmin(n, fd);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		out = n + '0';
		write(fd, &out, 1);
	}
}
