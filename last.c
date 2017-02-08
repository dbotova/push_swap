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
	return (0);
}

static int	check_a(t_stack *stack)
{
	if (stack->b_used != 0 && stack->a_used &&
		get_after(stack->a[stack->a_start], stack->b[stack->b_end], stack))
		return (1);
	return (0);
}

static int	find_next(t_stack *stack)
{
	int cur;
	int result;

	cur = stack->a_start;
	result = 0;
	while (!get_after(stack->b[stack->b_start], stack->a[cur], stack) && result < stack->size)
	{
		cur = get_next(stack->size, cur);
		result++;
	}
	if (result > stack->size - 1)
		result = result - stack->size;
	if (result == stack->size)
		result = -1;
	return (result);
}

static void	roll_a_next(t_stack *stack, int i)
{
	int next;

	if (stack->a[stack->a_start] <= stack->a[i])
	{
		while (!get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack))
		{
			next = get_next(stack->size, stack->a_start);
			if (get_after(stack->a[next], stack->a[stack->a_start], stack))
			{
				sa_swap(stack);
				ft_putstr("SA - 1\n");
				stack->counter++;
				// ft_print_both(stack);
				// getchar();
			}
			else
			{
				ra_swap(stack);
				ft_putstr("RA - ++\n");
				stack->counter++;
				// ft_print_both(stack);
				// getchar();
			}
		}
	}
	else
	{
		while (!get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack))
		{
			next = get_next(stack->size, stack->a_start);
			if (get_after(stack->a[next], stack->a[stack->a_start], stack))
			{
				sa_swap(stack);
				ft_putstr("SA - 1\n");
				next = get_next(stack->size, stack->a_start);
				stack->counter++;
				// ft_print_both(stack);
				// getchar();
			}
			else
			{
				rra_swap(stack);
				ft_putstr("RRA - ++\n");
				stack->counter++;
				printf("counter: %d\n", stack->counter);
				// ft_print_both(stack);
				// getchar();
			}
		}
	}
}

static void	merg_b(t_stack *stack)
{
	int next;
	int next_a;
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
		if (stack->a[stack->a_start] == stack->min)
		{
			ra_swap(stack);
			stack->counter++;
			ft_putstr("RA -- ##\n");
			// ft_print_both(stack);
			// getchar();
		}
		if (stack->b_used > 1 && (!get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack)
			|| get_after(stack->a[stack->a_end], stack->b[stack->b_start], stack) ||
			!get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack)))
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
				ft_putstr("RB -- ##\n");
				ft_print_both(stack);
				getchar();
			}
		}
		else
		{
			next_a = get_next(stack->size, stack->a_start);
			while(!get_after(stack->b[stack->b_start], stack->a[stack->a_start], stack) && stack->a_used > 1)
			{
				if (stack->b_used > 1 && !get_after(stack->b[stack->b_start], stack->a[next_a], stack))
				{
					rr_swap(stack);
					stack->counter++;
					ft_putstr("RR -- !!\n");
					next_a = get_next(stack->size, stack->a_start);
					// ft_print_both(stack);
					// getchar();
				}
				else
				{
					ra_swap(stack);
					stack->counter++;
					ft_putstr("RA -- #\n");
					next_a = get_next(stack->size, stack->a_start);
					// ft_print_both(stack);
					// getchar();
				}
			}
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
			push_a(stack);
	}
	roll_a(stack);
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
		// if (get_after(stack->b[stack->b_end], stack->b[stack->b_start], stack) && stack->b_used > 1)
		// {
		// 	rr_swap(stack);
		// 	stack->counter++;
		// 	ft_putstr("RR -- ##\n");
		// 	// ft_print_both(stack);
		// 	// getchar();
		// }
		//else
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
		// i = find_next(stack);
		// printf("LAST RESORT\n");
		// // ft_print_both(stack);
		// // getchar();
		// if (stack->a[stack->a_start] == stack->min &&
		// !is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
		// {
		// 	ra_swap(stack);
		// 	stack->counter++;
		// 	ft_putstr("RA - min\n");
		// 	// ft_print_both(stack);
		// 	// getchar();
		// }
		// if ((!stack->b_used || i < 0) && !is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
		// {
		// 	pb_swap(stack);
		// 	stack->counter++;
		// 	ft_putstr("PB - 0\n");
		// 	ft_print_both(stack);
		// 	getchar();
		// }
		// else if (!is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
		if (stack->b_used != stack->size && !is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
		{
			// roll_a_next(stack, i);
			// push_b(stack);
			roll_b(stack);
			push_b(stack);
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
