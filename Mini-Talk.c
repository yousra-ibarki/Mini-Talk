#include "libft.h"
#include <unistd.h>
#include <stdio.h>
int main()
{
	int a = 0;
	printf("hello this is the first try :");
	sleep(3);
	printf("just enter any number");
	scanf("%d", &a);
	if(a >= 0)
	printf("%d is P number\nprogram is finished", a);
	else
	printf("%d is a N number\nprogram is finished", a);
}