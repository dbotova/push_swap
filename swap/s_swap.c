#include "../push_swap.h"

void sa_swap (t_stack *stack)
{
	int tmp;
	int n;

	tmp = 0;
	if (stack->a_start == stack->size - 1)
		n = 0;
	else
		n = stack->a_start + 1;
	if (stack->a_used > 1)
	{
		tmp = stack->a[stack->a_start];
		stack->a[stack->a_start] = stack->a[n];
		stack->a[n] = tmp;
	}
}

void sb_swap (t_stack *stack)
{
	int tmp;
	int n;

	tmp = 0;
	if (stack->b_start == stack->size - 1)
		n = 0;
	else
		n = stack->b_start + 1;
	if (stack->b_used > 1)
	{
		tmp = stack->b[stack->b_start];
		stack->b[stack->b_start] = stack->b[n];
		stack->b[n] = tmp;
	}
}