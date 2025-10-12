#include "builtin.h"

void c_pwd(char **line)
{
    (void)line;
    printf("%s\n",getenv("PWD"));
}