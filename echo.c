#include "builtin.h"

static void echo_print(char **line)
{
    int i = CMD + 1;
    while(line[i])
    {
        printf("%s",line[i++]);
        if(line[i])
            printf(" ");
    }
}

void c_echo(char **line)
{
	if (!line[OPT])
		printf("\n");
	else if (!ft_strncmp(line[OPT], "-n", 3))
	{
		line++;
		echo_print(line);
	}
	else
	{
		echo_print(line);
		printf("\n");
	}
}