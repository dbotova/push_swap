#include "../push_swap.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char *src;

	src = ptr;
	while (num)
	{
		*src = (unsigned char)value;
		src++;
		num--;
	}
	return (ptr);
}
