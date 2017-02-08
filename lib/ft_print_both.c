#include "../push_swap.h"

void	ft_print_both(t_stack *stack)
{
	int i;
	int j;
	int	counter;

	i = stack->a_start;
	j = stack->b_start;
	counter = 0;
	while (counter < stack->size)
	{
		if (i == stack->size)
			i = 0;
		ft_putstr(ft_itoa_base(stack->a[i++], 10));
		ft_putstr("          ");
		if (j == stack->size)
			j = 0;
		ft_putstr(ft_itoa_base(stack->b[j++], 10));
		ft_putchar('\n');
		counter++;
	}
}