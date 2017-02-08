#include "../push_swap.h"

void	a_move_up(t_stack *stack)
{
	if (stack->a_used == stack->size)
	{
		stack->a_end = stack->a_start;
		if (stack->a_start == stack->size - 1)
			stack->a_start = 0;
		else
			stack->a_start++;
	}
	else if (stack->a_used > 2)
	{
		if (stack->a_end == stack->size - 1)
			stack->a_end = 0;
		else
			stack->a_end++;
		stack->a[stack->a_end] = stack->a[stack->a_start];
		stack->a[stack->a_start] = 0;
		if (stack->a_start == stack->size - 1)
			stack->a_start = 0;
		else
			stack->a_start++;
	}
}

void	b_move_up(t_stack *stack)
{
	if (stack->b_used == stack->size)
	{
		stack->b_end = stack->b_start;
		if (stack->b_start == stack->size - 1)
			stack->b_start = 0;
		else
			stack->b_start++;
	}
	else if (stack->b_used > 2)
	{
		if (stack->b_end == stack->size - 1)
			stack->b_end = 0;
		else
			stack->b_end++;
		stack->b[stack->b_end] = stack->b[stack->b_start];
		stack->b[stack->b_start] = 0;
		if (stack->b_start == stack->size - 1)
			stack->b_start = 0;
		else
			stack->b_start++;
	}
}

void	a_move_down(t_stack *stack)
{
	if (stack->a_used == stack->size)
	{
		stack->a_start = stack->a_end;
		if (stack->a_end == 0)
			stack->a_end = stack->size - 1;
		else
			stack->a_end--;
	}
	else if (stack->a_used > 2)
	{
		if (stack->a_start == 0)
			stack->a_start = stack->size - 1;
		else
			stack->a_start--;
		stack->a[stack->a_start] = stack->a[stack->a_end];
		stack->a[stack->a_end] = 0;
		if (stack->a_end == 0)
			stack->a_end = stack->size - 1;
		else
			stack->a_end--;
	}
}

void	b_move_down(t_stack *stack)
{
	if (stack->b_used == stack->size)
	{
		stack->b_start = stack->b_end;
		if (stack->b_end == 0)
			stack->b_end = stack->size - 1;
		else
			stack->b_end--;
	}
	else if (stack->b_used > 2)
	{
		if (stack->b_start == 0)
			stack->b_start = stack->size - 1;
		else
			stack->b_start--;
		stack->b[stack->b_start] = stack->b[stack->b_end];
		stack->b[stack->b_end] = 0;
		if (stack->b_end == 0)
			stack->b_end = stack->size - 1;
		else
			stack->b_end--;
	}
}
