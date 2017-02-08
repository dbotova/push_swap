#include "../push_swap.h"

static	int	move_down(int size, int n)
{
	if (n == size - 1)
		return (0);
	else
		return (n + 1);
}

static	int	move_up(int size, int n)
{
	if (n == 0)
		return (size - 1);
	else
		return (n - 1);
}

void	pa_swap(t_stack *stack)
{
	if (stack->b_used != 0)
	{
		if (stack->a_used > 0)
			stack->a_start = move_up(stack->size, stack->a_start);
		stack->a[stack->a_start] = stack->b[stack->b_start];
		stack->b[stack->b_start] = 0;
		stack->b_start = move_down(stack->size, stack->b_start);
		stack->b_used--;
		stack->a_used++;
		if (stack->b_used == 0)
			stack->b_start = stack->b_end;
	}
}

void	pb_swap(t_stack *stack)
{
	if (stack->a_used != 0)
	{
		if (stack->b_used > 0)
			stack->b_start = move_up(stack->size, stack->b_start);
		stack->b[stack->b_start] = stack->a[stack->a_start];
		stack->a[stack->a_start] = 0;
		stack->a_start = move_down(stack->size, stack->a_start);
		stack->a_used--;
		stack->b_used++;
		if (stack->a_used == 0)
			stack->a_start = stack->a_end;
	}
}