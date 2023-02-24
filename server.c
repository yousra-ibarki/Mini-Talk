#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "printf/ft_printf.h"
//, siginfo_t *info, void *context
static void receivemsg(int sig, siginfo_t *info, void *context)
{
	static int message;
	static int i;
	static pid_t pid;

	if(pid != info->si_pid)
	{
		pid = info->si_pid;
		message = 0;
		i = 0;
	}
	if(sig == SIGUSR1)
		message |= (1 << i);
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
	pid_t pid = getpid();
	struct sigaction sighand;
	sighand.sa_sigaction = &receivemsg;
	sighand.sa_flags = SA_SIGINFO;
	ft_printf("Your PID is : %d\nYour message is : ", pid);
    //sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact)
		while(1)
		{
			sigaction(SIGUSR1, &sighand, 0);
			sigaction(SIGUSR2, &sighand, 0);
			pause();
		}	
	//while(1);
}