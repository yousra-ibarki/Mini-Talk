#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

static void ft_fix(int sig)
{
	int message;
	int i;

	i = 0;
	message = 0;

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
		signal(SIGUSR1, ft_fix);
		signal(SIGUSR2, ft_fix);
		//pause();
		while(1);
	
	return (0);
}