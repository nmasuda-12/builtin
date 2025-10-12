#include "builtin.h"

void c_exit(char **line)
{
    size_t i;
    if(!line[CMD + 1])
        c_echo(line);

    num = ft_atoi(line[CMD + 1]);
    while(0 <= num && num <= 255)
        num = num / 256;
}
