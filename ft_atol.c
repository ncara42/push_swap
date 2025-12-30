#include "push_swap.h"

long	*ft_atol(char *argv_char)
{
	int		i;
	int		sign;
	long	result;
	long	*argv_long;

	argv_long = malloc(sizeof(long));
	if (!argv_long)
		return (NULL);
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
	*argv_long = result * sign;
	return (argv_long);
}
