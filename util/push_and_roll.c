#include "../push_swap.h"

void	push_b(t_stack *stack)
{
	int next;

	next = get_next(stack->size, stack->b_start);
	pb_swap(stack);
	ft_putstr("PB - 4\n");
	stack->counter++;
	// ft_print_both(stack);
	// getchar();
	while (get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack) &&
		(!get_after(stack->a[stack->a_end], stack->a[stack->a_start], stack)) &&
		!is_sorted(stack->a, stack->size, stack->a_start, stack->a_used) &&
		!get_after(stack->b[stack->b_start], stack->b[next], stack))
	{
		pb_swap(stack);
		ft_putstr("PB - 5\n");
		next = get_next(stack->size, stack->b_start);
		stack->counter++;
		// ft_print_both(stack);
		// getchar();
	}
}

void	push_a(t_stack *stack)
{
	int next;

	
	pa_swap(stack);
	stack->counter++;
	ft_putstr("PA -- $$\n");
	ft_print_both(stack);
	getchar();
	next = get_next(stack->size, stack->a_start);
	if (stack->b_used > 1 && !get_after(stack->b[stack->b_start], stack->a[next], stack))
	{
		rr_swap(stack);
		stack->counter++;
		ft_putstr("RR -- !!\n");
		next = get_next(stack->size, stack->a_start);
		ft_print_both(stack);
		getchar();
	}
	else
	{
		ra_swap(stack);
		stack->counter++;
		ft_putstr("RA -- #\n");
		ft_print_both(stack);
		getchar();
	}
}

void	roll_a(t_stack *stack)
{
	int mid;

	mid = get_mid(stack->a_start, stack->size, stack->a_used);
	if (stack->a[stack->a_start] <= stack->a[mid])
	{
		while (stack->a[stack->a_start] != stack->min)
		{
			ra_swap(stack);
			ft_putstr("RA - ^^\n");
			stack->counter++;
			// ft_print_both(stack);
			// getchar();
		}
	}
	else
	{
		while (stack->a[stack->a_start] != stack->min)
		{
			ra_swap(stack);
			ft_putstr("RA - ^^\n");
			stack->counter++;
			// ft_print_both(stack);
			// getchar();
		}
	}
}

void	roll_b(t_stack *stack)
{
	int min;
	int max;

	min = get_min(stack->b, stack->size, stack->b_start, stack->b_used);
	max = get_max(stack->b, stack->size, stack->b_start, stack->b_used);
	if (stack->b_used <= 1)
	{
		pb_swap(stack);
		stack->counter++;
		ft_putstr("PB -- ^\n");
		// ft_print_both(stack);
		// getchar();
	}
	else if (stack->a[stack->a_start] > min && stack->a[stack->a_start] < max)
	{
		while (stack->b[stack->b_start] > stack->a[stack->a_start])
		{
			if (get_after(stack->a[stack->a_end], stack->a[stack->a_start], stack))
			{
				rr_swap(stack);
				stack->counter++;
				ft_putstr("RR -- ##\n");
				// ft_print_both(stack);
				// getchar();
			}
			else
			{
				rb_swap(stack);
				stack->counter++;
				ft_putstr("RB -- ^^\n");
				// ft_print_both(stack);
				// getchar();
			}
		}
	}
	else
	{
		while (stack->b[stack->b_start] != min)
		{
			if (get_after(stack->a[stack->a_end], stack->a[stack->a_start], stack))
			{
				rr_swap(stack);
				stack->counter++;
				ft_putstr("RR -- ##\n");
				// ft_print_both(stack);
				// getchar();
			}
			else
			{
				rb_swap(stack);
				stack->counter++;
				ft_putstr("RB -- ^^\n");
				// ft_print_both(stack);
				// getchar();
			}
		}
	}
}