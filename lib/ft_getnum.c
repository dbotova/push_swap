#include "../push_swap.h"

int	ft_getnum(char *str, int *value)
{
	int size;
	int i;

	size = 0;
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] == '0')
	{
		i++;
		size++;
	}
	*value = ft_atoi(str);
	size += ft_nbrsize(*value);
	return (size);
}
