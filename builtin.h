#ifndef _BUILTIN_H_
# define _BUILTIN_H_

# define CMD 1
# define OPT 2
# define ERROR -1

# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

//-----main---------
void	built_in_check(char **line, char **ev);

//-----command------
void	c_echo(char **line);
void	c_pwd(char **line);
void	c_env(char **line, char **ev);
char	**c_unset(char **line, char **ev);

//-----仮置系--------
void	error(char *mess, char **line);
void	c_check(char **check);

//-----utils---------
int		ft_strncmp(char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
int		ft_atoi(char *st);
void	*ft_memmove(void *dest, const void *src, size_t n);

#endif