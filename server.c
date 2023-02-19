#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"
//int glvar;

static void handler(int sig)
{
	static int i;
	static int bit;

	if(sig == SIGUSR1)
	
		// temp = 1 << i;
		// c |= temp;
		i |= (0x01 << bit);

		bit++;
	if(bit == 8)
	{
		printf("%c", i);
		i = 0;
		bit = 0;
	}

}
int main(void)
{
	//struct sigaction varaction;
	ft_printf("Your PID is : %d\n", getpid());
	//varaction.sa_sigaction = handler;
	//varaction.sa_flags = 
	while(1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return 0;
}