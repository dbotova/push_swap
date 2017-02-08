#include "../push_swap.h"

int	ft_nbrsize(long n)
{
	int size;

	size = 1;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}
