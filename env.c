#include "builtin.h"

void	c_env(char **line, char **ev)
{
	int	i;

	(void)line;
	i = 0;
	while (ev[i])
    {
        if(!ft_strncmp(ev[i],"_=",2))
        {
            printf("_=/usr/bin/env\n");
            break;
        }
        else
		    printf("%s\n", ev[i++]);
    }
}
