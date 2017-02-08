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
	int max;
	int min;
	int mid;
	int next_b;

	next = get_next(stack->size, stack->a_start);
	if (!stack->a_used)
		merg_b(stack);
	if (is_sorted(stack->a, stack->size, stack->a_start, stack->a_used) && !stack->b_used)
		return (1);

	printf("NEW RUN\n");
	// ft_print_both(stack);
	// getchar();
	if (stack->a[stack->a_start] > stack->a[next])
	{
		sa_swap(stack);
		ft_putstr("SA - 1\n");
		next = get_next(stack->size, stack->a_start);
		stack->counter++;
		// ft_print_both(stack);
		// getchar();
	}

	if ((get_after(stack->a[stack->a_start], stack->a[next], stack) ||
		get_after(stack->a[stack->a_end], stack->a[stack->a_start], stack)) && !check_b(stack) && stack->a_used)
	{
		ra_swap(stack);
		ft_putstr("RA - 2\n");
		stack->counter++;
		next = get_next(stack->size, stack->a_start);
		// ft_print_both(stack);
		// getchar();

		while (get_after(stack->a[stack->a_end], stack->a[stack->a_start], stack) && !check_b(stack))
		{
			if (get_after(stack->b[stack->b_start], stack->b[stack->b_end], stack) && stack->b_used)
			{
				rr_swap(stack);
				ft_putstr("RR - 33\n");
				stack->counter++;
				next = get_next(stack->size, stack->a_start);
				// ft_print_both(stack);
				// getchar();
			}
			else
			{
				ra_swap(stack);
				ft_putstr("RA - 3\n");
				stack->counter++;
				next = get_next(stack->size, stack->a_start);
				// ft_print_both(stack);
				// getchar();
			}

			if (is_sorted(stack->a, stack->size, stack->a_start, stack->a_used) && !stack->b_used)
				return (1);
		}
	}
	if (!get_after(stack->a[stack->a_end], stack->a[stack->a_start], stack) && !check_b(stack))
		push_b(stack);
	while (get_after(stack->a[stack->a_end], stack->b[stack->b_start], stack) && stack->b_used)
	{
		push_a(stack);
		// pa_swap(stack);
		// stack->counter++;
		// ft_putstr("PA -- $$\n");
		// ft_print_both(stack);
		// getchar();

		// ra_swap(stack);
		// ft_putstr("RA - $$\n");
		// stack->counter++;
		// ft_print_both(stack);
		// getchar();
	}
	while (get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack) && stack->b_used)
	{
		pa_swap(stack);
		stack->counter++;
		ft_putstr("PA -- 8\n");
		// ft_print_both(stack);
		// getchar();
	}
	if (stack->a[stack->a_start] == stack->min && stack->b[stack->b_start] == stack->max && stack->b_used)
	{
		pa_swap(stack);
		stack->counter++;
		ft_putstr("PA -- 6\n");
		// ft_print_both(stack);
		// getchar();
		if (!get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack) && stack->b_used)
		{
			ra_swap(stack);
			ft_putstr("RA - !!\n");
			stack->counter++;
			next = get_next(stack->size, stack->a_start);
			// ft_print_both(stack);
			// getchar();
		}
		while (get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack) && stack->b_used)
	 	{
	 		pa_swap(stack);
			stack->counter++;
			ft_putstr("PA -- 7\n");
			// ft_print_both(stack);
			// getchar();
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