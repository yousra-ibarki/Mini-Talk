#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "printf/ft_printf.h"

static void receivemsg(int sig, siginfo_t *info, void *context)
{
	static int message;
	static int i;
	static pid_t pid = 0;
	if(pid != info->si_pid)
		pid = info->si_pid;

	if(sig == SIGUSR1)
		message = message | (1 << i);
	i++;
	if(i == 8)
	{
		ft_printf("%c", message);
		message = 0;
		i = 0;
	}

}

int main(void)
{
	struct sigaction handsig;
	handsig.sa_sigaction = &receivemsg;
	handsig.sa_flags = SA_SIGINFO;

	ft_printf("Your PID is : %d\nYour message is : ", getpid());
    //sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact)
		sigaction(SIGUSR1, &handsig, NULL);
		sigaction(SIGUSR2, &handsig, NULL);
		
		while(1);
}