#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
// A = 01000001
int global;
int main(int ac, char **av)
{
	int pid = ft_atoi(av[1]);
	if(ac <= 3)
	{
		if(kill(av[1], SIGUSR1) == 1)
		{
			kill(av[1], SIGUSR1);
		}
		else if(kill(av[1], SIGUSR1) == 0){

		}
		{

		}
		printf("%d\n", global);
		printf("sigusr1 is %d\n", SIGUSR1);
		printf("sigusr1 is %d\n", SIGUSR2);
		//printf("the first one is :%s\nthe pid is:%s\nthe string is:%s", av[0], av[1], av[2]);
	//kill(pid, SIGUSR1);
	}
	else
	return 0;
}