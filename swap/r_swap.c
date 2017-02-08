#include "../push_swap.h"

void	ra_swap(t_stack *stack)
{
	int tmp;

	if (stack->a_used == 2)
		sa_swap(stack);
	else if (stack->a_start != stack->a_end)
		a_move_up(stack);
}

void	rra_swap(t_stack *stack)
{
	int tmp;

	if (stack->a_used == 2)
		sa_swap(stack);
	else if (stack->a_start != stack->a_end)
		a_move_down(stack);
}

void	rb_swap(t_stack *stack)
{
	int tmp;

	if (stack->b_used == 2)
		sb_swap(stack);
	else if (stack->b_start != stack->b_end)
		b_move_up(stack);
}

void	rrb_swap(t_stack *stack)
{
	int tmp;

	if (stack->b_used == 2)
		sb_swap(stack);
	else if (stack->b_start != stack->b_end)
		b_move_down(stack);
}