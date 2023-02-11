#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

//int sigemptyset(sigset_t *set);
int	checkoverflow(unsigned long long out, int sign)
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

void ft_dtob(int av)
{
    char arr[32]; 
    int i = 0;
    printf("hello girl");
    // if(av == 0)
    //     return ;
    while(av > 0)
    {
         arr[i] = av % 2;
        av /= 2;
        i++;
    }
    for(int i = 0; i < strlen(arr);i++)
    printf("decimal to byte is : %c\n", arr[i]);
}
int main(int ac, char **av)
{
    int pid = ft_atoi(av[1]);
    char arr[32] = ft_dtob(pid); 
    //signal()
}
