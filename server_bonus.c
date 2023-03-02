/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:38:59 by yoibarki          #+#    #+#             */
/*   Updated: 2023/02/27 13:43:37 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

static void	receivemsg(int sig, siginfo_t *info, void *context)
{
	static long int	message;
	static int		i;
	static pid_t	pid;
	static int		char_lenght;
	static char		buff[4];
	int j = 0;

	(void)context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		message = 0;
		i = 0;
		char_lenght = 0;
	}
	if (sig == SIGUSR1)
	{
		message |= (1 << i);
	}
	i++;
	if (i == 8)
	{
		if (message >= 240)
			char_lenght = 3;
		else if (message >= 224)
			char_lenght = 2;
		else if (message >= 192)
			char_lenght = 1;
		else
			char_lenght = 0;
		char_lenght = char_lenght * 8;
	}
	//printf("%d\n",char_lenght);
	if (!char_lenght && i >= 8)
	{
		if (i == 8)
			ft_printf("%c", message);
		else
		{
			while(j < 4)
			{
				buff[j] = message >> j * 8;
				j++;
			}
			ft_printf("%s", buff);
			j = 0;
		}
		if (message == 0)
			kill(info->si_pid, SIGUSR2);
		message = 0;
		i = 0;
		char_lenght = 0;
	}
	else if (i >= 8)
		char_lenght--;
}

int	main(void)
{
	struct sigaction	sighand;

	sighand.sa_sigaction = &receivemsg;
	sighand.sa_flags = SA_SIGINFO;
	ft_printf("Your PID is : %d\nYour message is : ", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sighand, 0);
		sigaction(SIGUSR2, &sighand, 0);
		pause();
	}
}
