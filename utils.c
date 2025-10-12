#include "builtin.h"

int	ft_strncmp(char *s1, const char *s2, size_t n)
{
	while (n && *s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		(void)(n--, s1++, s2++);
	}
	if (n)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
