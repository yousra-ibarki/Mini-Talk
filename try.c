#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"
//client
int main(int ac, char **av)
{
	int i;
	static int pid;

	i = 0;
	if(ac != 3)
	{
		ft_printf("Error : Check the number of arguments\n");
		return (1);
	}

	else
	{
		pid = ft_atoi(av[1]);
		while(av[2][i] != '\0')
		{
			sendmessage(av[2][i], pid);	 //kill(siguser, pid)
			i++;
		}
	}
	return 0;
}
//server
int main(void)
{   
	struct sigaction sighand;
	sighand.sa_sigaction = &receivemsg;
	sighand.sa_flags = SA_SIGINFO;
	ft_printf("Your PID is : %d\nYour message is : ", getpid());
		while(1)
		{
			sigaction(SIGUSR1, &sighand, 0);
			sigaction(SIGUSR2, &sighand, 0);
			pause();
		}	
}