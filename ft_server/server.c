/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:43:55 by yoibarki          #+#    #+#             */
/*   Updated: 2023/02/27 14:09:48 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"

static void	receivemsg(int sig, siginfo_t *info, void *context)
{
	static int		message;
	static int		i;
	static pid_t	pid;

	(void)context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		message = 0;
		i = 0;
	}
	if (sig == SIGUSR1)
		message |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", message);
		message = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sighand;

	sighand.sa_sigaction = &receivemsg;
	//sighand.sa_flags = SA_SIGINFO;
	ft_printf("Your PID is : %d\nYour message is : ", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sighand, 0);
		sigaction(SIGUSR2, &sighand, 0);
		pause();
	}
}
