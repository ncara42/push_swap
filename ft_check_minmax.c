#include "push_swap.h"

int check_minmax(char **argv)
{
	int		i;
	long	*num;

	i = 1;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (!num)
			return (0);
		if (*num < INT_MIN || *num > INT_MAX)
		{
			free(num);
			return (0);
		}
		free(num);
		i++;
	}
	return (1);
}