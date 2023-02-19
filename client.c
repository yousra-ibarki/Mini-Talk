#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	ft_fonction(int pid, char i)
{
	int c = 0;
	while(c <= 7)
			{
				if((i & (1 << c)) != 0)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				usleep(100);
				c++;
			}
}
int main(int ac, char **av)
{
	int i = 0;
	char c = 0;
	int pid;
	if(ac == 3)
	{
		pid = ft_atoi(av[1]);
		while(av[2][i] != '\0')
		{
			ft_fonction(pid, av[2][i]);	
			i++;
		}
		ft_fonction(pid, '\n');
	}
	else
		{
			printf("Error : Check the number of arguments\n");
			return 1;
		}
	return 0;
}