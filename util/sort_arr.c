/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 21:53:25 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/18 21:53:26 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_b(t_stack *stack)
{

	if (stack->b_used != 0 &&
		get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack))
			return (1);
	if ((stack->a[stack->a_start] == stack->min && stack->b[stack->b_start] == stack->max) ||
				(stack->a[stack->a_start] == stack->max && stack->b[stack->b_start] == stack->min))
				return (1); 
	return (0);
}

static void	merg_b(t_stack *stack)
{
	printf("\n\n\n SCORE:  %d\n\n\n", stack->counter);
	ft_print_both(stack);
	getchar();

	if (!stack->a_used)
	{
		pa_swap(stack);
		stack->counter++;
		ft_putstr("PA -- 8\n");
		// ft_print_both(stack);
		// getchar();
	}
	while (stack->b_used)
	{
		if (stack->b_used && (!get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack)
			|| get_after(stack->a[stack->a_end], stack->b[stack->b_start], stack)))
		{
			rb_swap(stack);
			stack->counter++;
			ft_putstr("RB -- ##\n");
			// ft_print_both(stack);
			// getchar();
		}
		while (get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack) && stack->b_used)
		{
			pa_swap(stack);
			stack->counter++;
			ft_putstr("PA -- ##\n");
			// ft_print_both(stack);
			// getchar();
		}
		while ((get_after(stack->b[stack->b_start], stack->a[stack->a_end], stack) ||
			get_after(stack->a[stack->a_end], stack->b[stack->b_start], stack)) && stack->b_used)
		{
			push_a(stack);
			// pa_swap(stack);
			// stack->counter++;
			// ft_putstr("PA -- @@\n");
			// // ft_print_both(stack);
			// // getchar();

			// ra_swap(stack);
			// ft_putstr("RA - @@\n");
			// stack->counter++;
			// // ft_print_both(stack);
			// // getchar();
		}
		if (((stack->a[stack->a_start] == stack->min && stack->b[stack->b_start] == stack->max) ||
				(stack->a[stack->a_start] == stack->max && stack->b[stack->b_start] == stack->min)) && stack->b_used)
		{
			pa_swap(stack);
			stack->counter++;
			ft_putstr("PA -- ^^\n");
			// ft_print_both(stack);
			// getchar();
			if (!get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack) && stack->b_used)
			{
				ra_swap(stack);
				ft_putstr("RA - ^^\n");
				stack->counter++;
				// ft_print_both(stack);
				// getchar();
			}
			while (get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack) && stack->b_used)
		 	{
		 		pa_swap(stack);
				stack->counter++;
				ft_putstr("PA -- ^^\n");
				// ft_print_both(stack);
				// getchar();
		 	}
		}
	}
}

static int	sort_a(t_stack *stack)
{
	int next;
	int next_b;
	int mid;
	int i;

	next = get_next(stack->size, stack->a_start);
	i = 0;
	if (!stack->a_used ||( is_sorted_rev(stack->b, stack->size, stack->b_start, stack->b_used)
		&& stack->b_used && is_sorted(stack->a, stack->size, stack->a_start, stack->a_used)))
		merg_b(stack);
	if (is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
		merg_b(stack);
	if (is_sorted(stack->a, stack->size, stack->a_start, stack->a_used) && !stack->b_used)
		return (1);

	printf("NEW RUN\n");
	// ft_print_both(stack);
	// getchar();
	if (get_after(stack->a[next], stack->a[stack->a_start], stack))
	{
		sa_swap(stack);
		ft_putstr("SA - 1\n");
		next = get_next(stack->size, stack->a_start);
		stack->counter++;
		// ft_print_both(stack);
		// getchar();
	}
	else if (stack->a[stack->a_start] > stack->a[next] && stack->a_used > 1 &&
		!is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
	{
		if (get_after(stack->b[stack->b_end], stack->b[stack->b_start], stack) && stack->b_used > 1)
		{
			rr_swap(stack);
			stack->counter++;
			ft_putstr("RR -- ##\n");
			// ft_print_both(stack);
			// getchar();
		}
		else
		{
			ra_swap(stack);
			stack->counter++;
			ft_putstr("RA -- 8\n");
			// ft_print_both(stack);
			// getchar();
		}
		return(0);
	}
	next = get_next(stack->size, stack->a_start);
	if ((get_after(stack->a[stack->a_start], stack->a[next], stack) || check_b(stack)) && stack->b_used &&
		!is_sorted(stack->a, stack->size, stack->a_start, stack->a_used) &&
		!get_after(stack->a[stack->a_end], stack->a[stack->a_start], stack) && stack->a_used > 1)
		push_b(stack);
	if (get_after(stack->a[stack->a_end], stack->a[stack->a_start], stack) && stack->a_used > 1 &&
		!is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
	{
		while (get_after(stack->a[stack->a_end], stack->a[stack->a_start], stack))
		{
			if (is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
				return (1);
			if ((get_after(stack->b[stack->b_start], stack->b[stack->b_end], stack) ||
				stack->b[stack->b_start] < stack->b[stack->b_end]) && stack->b_used > 1)
			{
				rrr_swap(stack);
				stack->counter++;
				ft_putstr("RRR -- 8\n");
				// ft_print_both(stack);
				// getchar();	
			}
			else
			{
				rra_swap(stack);
				stack->counter++;
				ft_putstr("RRA -- 8\n");
				ft_print_both(stack);
				getchar();
			}
		}
	}
	else
	{
	// 	if (stack->a_used && stack->b_used)
	// 	{
	// 		rr_swap(stack);
	// 		stack->counter++;
	// 		ft_putstr("RR -- 10\n");
	// 		// ft_print_both(stack);
	// 		// getchar();
	// 	}
	// 	else
	// 	{
	// 		ra_swap(stack);
	// 		stack->counter++;
	// 		ft_putstr("RA -- 10\n");
	// 		// ft_print_both(stack);
	// 		// getchar();
	// 	}


		while (get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack) && stack->b_used)
		{
			pa_swap(stack);
			stack->counter++;
			ft_putstr("PA -- 8\n");
			// ft_print_both(stack);
			// getchar();
		}
	}
	return (0);
}

void	sort_arr(t_stack *stack)
{
	int mid;

	while (!sort_a(stack))
		;

}
