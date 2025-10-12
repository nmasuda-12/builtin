#ifndef _BUILTIN_H_
# define _BUILTIN_H_

# define CMD 1
# define OPT 2

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

//-----main---------
void	built_in_check(char **line, char **ev);

//-----command------
void	c_echo(char **line);
void    c_pwd(char **line);
void	c_env(char **line, char **ev);

//-----error--------


//-----utils---------
int		ft_strncmp(char *s1, const char *s2, size_t n);

#endif