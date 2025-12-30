#include "push_swap.h"

long	ft_atol(char *argv_char)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (argv_char[i])
	{
		if (argv_char[i] == '-' || argv_char[i] == '+')
		{
			if (argv_char[i] == '-')
				sign = -1;
			i++;
		}
		result = result * 10 + (argv_char[i] - '0');
		i++;
	}
	return (result * sign);
}
