#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

static int	checkoverflow(unsigned long long out, int sign)
{
	if (out > 2146218951891489519)
	{
		if (sign == -1)
			return (0);
		else
			return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long long	out;
	int					i;
	int					sign;

	out = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out *= 10;
		out += str[i++] - '0';
		if (checkoverflow(out, sign) == 0)
			return (0);
		else if (checkoverflow(out, sign) == -1)
			return (-1);
	}
	return (out * sign);
}

void	sendmessage(char i, int pid)
{
	int c;
	
	c = 0;
	while(c <= 7)
			{
				 if((i & (1 << c)) != 0)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				usleep(500);
				c++;
			}
}
//, siginfo_t *info, void *context
static void confirmation(int sig)
{
	if(sig == SIGUSR1)
		ft_printf("Well Done");
	else 
		ft_printf("Well Done", 1);

}
int main(int ac, char **av)
{
	int i;
	static int pid;
	// struct sigaction conf;
	// conf.sa_sigaction = &confirmation;
	// conf.sa_flags = SA_SIGINFO;
	

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
				signal(SIGUSR1, confirmation);
				signal(SIGUSR2, confirmation);
				sendmessage(av[2][i], pid);	
			i++;
		}
		// if(av[2][i] == '\0')
		// {
		// 	sendmessage('\0', pid);
		// 	//sigaction(SIGUSR2, &conf, NULL);
		// 	printf("dont");
		// 	//sleep(50);
		// }
	}
}