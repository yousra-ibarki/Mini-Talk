#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
int glvar;
void handler(int signum)
{
	printf("i just wanna sleep %d\n", signum);
	
}
int main(void)
{
	signal(SIGUSR1,handler);
	printf("The pid of your process is:%d", getpid());
	//signal(SIGUSR1, void (*func)(int))
	return 0;
}
// void handel(int seg)
// {
// 	printf("handel here %d\n", seg);
// }
// int main()
// {
// 	signal(SIGINT, handel);
// 	while(1);
// 	return 0;
// }