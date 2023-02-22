#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "printf/ft_printf.h"

static void ft_fix(int sig)
{
	static int message;
	static int i;

	if(sig == SIGUSR1)
		message = message | (1 << i);
	i++;
	if(i == 8)
	{
		printf("%c", message);
		message = 0;
		i = 0;
	}

}
int main(void)
{
	ft_printf("Your PID is : %d\nYour message is : ", getpid());
	while(1)
	{
		signal(SIGUSR1, ft_fix);
		signal(SIGUSR2, ft_fix);
		pause();
	}
	return 0;
}