/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:21:47 by yoibarki          #+#    #+#             */
/*   Updated: 2023/02/27 15:57:37 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	sendmessage(char i, int pid)
{
	int	c;

	c = 0;
	while (c <= 7)
	{
		if ((i & (1 << c)) != 0)
		{
			if (kill(pid, SIGUSR1) < 0)
			{
				ft_printf("WATCH OUT, Wrong PID 🥴");
				exit(1);
			}
		}
		else
			kill(pid, SIGUSR2);
		usleep(500);
		c++;
	}
}

static void	confirmation(int sig)
{
	ft_printf("Well Done 👌");
}

int	main(int ac, char **av)
{
	int			i;
	static int	pid;
	int			len;

	len = ft_strlen(av[2]);
	i = 0;
	if (ac != 3)
	{
		ft_printf("Error : Check the number of arguments\n");
		return (1);
	}
	else
	{
		pid = ft_atoi(av[1]);
		while (i <= len)
		{
			signal(SIGUSR2, confirmation);
			sendmessage(av[2][i], pid);
			i++;
		}
	}
}
