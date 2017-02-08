#include "../push_swap.h"

void	free_stack(t_stack **stack)
{
	SMART_FREE((*stack)->a);
	SMART_FREE((*stack)->b);
	SMART_FREE((*stack)->all);
	SMART_FREE(*stack);
}