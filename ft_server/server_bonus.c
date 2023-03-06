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
#include "../ft_printf/ft_printf.h"

struct		s_var
{
	int		i;
	pid_t	pid;
	int		nbr_byte;
	char	buff[4];
}			var_s;

static void	printmsg(int message)
{
	int	j;

	j = 0;
	if (var_s.i == 8)
		ft_printf("%c", message);
	else
	{
		while (j < 4)
		{
			var_s.buff[j] = message >> j * 8;
			j++;
		}
		ft_printf("%s", var_s.buff);
		j = 0;
	}
}

static void	checknbr_byte(int message)
{
	if (var_s.i == 8)
	{
		if (message >= 240)
			var_s.nbr_byte = 3;
		else if (message >= 224)
			var_s.nbr_byte = 2;
		else if (message >= 192)
			var_s.nbr_byte = 1;
		else
			var_s.nbr_byte = 0;
		var_s.nbr_byte = var_s.nbr_byte * 8;
	}
}

static void	receivemsg(int sig, siginfo_t *info, void *context)
{
	static int	message;

	(void)context;
	if (var_s.pid != info->si_pid)
	{
		var_s.pid = info->si_pid;
		message = 0;
		var_s.i = 0;
		var_s.nbr_byte = 0;
	}
	if (sig == SIGUSR1)
		message |= (1 << var_s.i);
	var_s.i++;
	checknbr_byte(message);
	if (!var_s.nbr_byte && var_s.i >= 8)
	{
		printmsg(message);
		if (message == 0)
			kill(info->si_pid, SIGUSR2);
		message = 0;
		var_s.i = 0;
		var_s.nbr_byte = 0;
	}
	else if (var_s.i >= 8)
		var_s.nbr_byte--;
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
