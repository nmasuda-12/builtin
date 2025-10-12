#include "builtin.h"

static bool	ft_overflow(long res)
{
	int	cnt;

	cnt = 0;
	while (res > 9)
	{
		res = res / 10;
		cnt++;
	}
	if (cnt > 10)
		return (false);
	if (cnt == 9)
		if (res > 7)
			return (false);
	return (true);
}

int	ft_atoi(char *st)
{
	long	res;

	res = 0;
	if (*st == '0')
		st++;
	while ('0' <= *st && *st <= '9' || *st == '+')
	{
		if (*st == '+')
			st++;
		res = res * 10 + (*st - '0');
		st++;
	}
	if (!('0' <= *st && *st <= '9' || *st == '+' || *st == '\0'))
		return (ERROR);
	if (ft_overflow(res) == false)
		return (ERROR);
	return (res);
}
