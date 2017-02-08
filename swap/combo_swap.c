#include "../push_swap.h"

void	ss_swap(t_stack *stack)
{
	sa_swap(stack);
	sb_swap(stack);
}

void	rr_swap(t_stack *stack)
{
	ra_swap(stack);
	rb_swap(stack);
}

void	rrr_swap(t_stack *stack)
{
	rra_swap(stack);
	rrb_swap(stack);
}