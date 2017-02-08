#include "../push_swap.h"

void	new_stack(t_stack **stack, int size)
{
	(*stack) = malloc(sizeof(t_stack));
	(*stack)->a = (int *)malloc(sizeof(int) * size);
	ft_memset((*stack)->a, 0, sizeof(int) * size);
	(*stack)->b = (int*)malloc(sizeof(int) * size);
	ft_memset((*stack)->b, 0, sizeof(int) * size);
	(*stack)->all = (int*)malloc(sizeof(int) * size);
	ft_memset((*stack)->all, 0, sizeof(int) * size);
	(*stack)->size = size;
	(*stack)->a_start = 0;
	(*stack)->a_end = size - 1;
	(*stack)->b_start = 0;
	(*stack)->b_end = 0;
	(*stack)->a_used = size;
	(*stack)->b_used = 0;
	(*stack)->counter = 0; //remove
	(*stack)->min = 0;
	(*stack)->max = 0;
}