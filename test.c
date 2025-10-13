#include <stdio.h>

int main()
{
	int i = 0;
	char *a = "12345";
	while(a[i])
		i++;
	printf("%d\n",i);
	return 0;
}
