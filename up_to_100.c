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

#include "push_swap.h"

static int	check_b(t_stack *stack)
{
	int next;

	if (stack->b_used != 0 &&
		stack->a[stack->a_start] < stack->b[stack->b_start] &&
			stack->a[stack->a_start] != stack->min)
	// if (stack->b_used != 0 && stack->b_used <= stack->size / 2 &&
	// 	stack->a[stack->a_start] < stack->b[stack->b_start])
		return (0);
	return (1);
}

static int	sort_b(t_stack *stack)
{
	int next;

	next = get_next(stack->size, stack->b_start);
	if (is_sorted_rev(stack->b, stack->size, stack->b_start, stack->b_used) || stack->b_used == 0)
		return (1);
	if (stack->b[stack->b_start] > stack->a[stack->a_start])
	{
		while (stack->b[stack->b_start] > stack->a[stack->a_start])
		{
			ra_swap(stack);
			stack->counter++;
			ft_putstr("RA ---\n");
			// ft_print_both(stack);
			// getchar();
		}
		pa_swap(stack);
		stack->counter++;
		ft_putstr("PA ---\n");
		// ft_print_both(stack);
		// getchar();
		while (!is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
		{
			rra_swap(stack);
			stack->counter++;
			ft_putstr("RRA ---\n");
			// ft_print_both(stack);
			// getchar();
		}
	}
	if (stack->b[stack->b_start] < stack->a[stack->a_start])
	{
		pa_swap(stack);
		stack->counter++;
		ft_putstr("PA ---\n");
		// ft_print_both(stack);
		// getchar();
	}
	if (stack->b[stack->b_start] < stack->b[next] && stack->b[stack->b_start] < stack->b[stack->b_end])
	{
		sb_swap(stack);
		stack->counter++;
		ft_putstr("SB ---\n");
		// ft_print_both(stack);
		// getchar();
	}
	else if (stack->b_used > 1)
	{
		if (stack->b[stack->b_start] > stack->b[next] && stack->b[stack->b_start] < stack->b[stack->b_end])
		{
			rb_swap(stack);
			stack->counter++;
			ft_putstr("RB ---\n");
			// ft_print_both(stack);
			// getchar();
		}
		else
		{
			rrb_swap(stack);
			ft_putstr("RRB ---\n");
			stack->counter++;
			// ft_print_both(stack);
			// getchar();
		}
	}
	if (stack->b_used == stack->size / 2)
		sort_b(stack);
	return (0);
}

static int	sort_a(t_stack *stack)
{
	int next;

	next = get_next(stack->size, stack->a_start);
	if (is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
	{
		if (is_sorted_rev(stack->b, stack->size, stack->b_start, stack->b_used))
			return (1);
		else
		{
			while (!sort_b(stack))
				;
		}
		return (0);
	}
	else
	{
		if (stack->a[stack->a_start] > stack->a[next] && (stack->a[stack->a_start] < stack->a[stack->a_end] || stack->a_used == 2))
		{
			if (stack->b[stack->b_start] < stack->b[next] && stack->b[stack->b_start] < stack->b[stack->b_end])
			{
				ss_swap(stack);
				stack->counter++;
				ft_putstr("SS - 5\n");
				// ft_print_both(stack);
				// getchar();
			}
			else
			{
				sa_swap(stack);
				ft_putstr("SA - 1\n");
				stack->counter++;
				// ft_print_both(stack);
				// getchar();
			}
		}
		if (stack->a[stack->a_start] < stack->a[next])
		{
			if (check_b(stack))
			// if (stack->b_used <= stack->size / 2)
			{
				pb_swap(stack);
				ft_putstr("PB - 2\n");
				stack->counter++;
				// ft_print_both(stack);
				// getchar();
			}
			else
			{
				while (stack->b[stack->b_start] > stack->a[stack->a_start] && stack->b_used > 1)
				{
					rb_swap(stack);
					stack->counter++;
					ft_putstr("RB\n");
					// ft_print_both(stack);
					// getchar();
				}
				pb_swap(stack);
				ft_putstr("PB\n");
				stack->counter++;
				// ft_print_both(stack);
				// getchar();
			}
		}
		else
		{
			ra_swap(stack);
			ft_putstr("RA - 4\n");
			stack->counter++;
			// ft_print_both(stack);
			// getchar();
		}
	}
	return (0);
}

void	sort(t_stack *stack)
{
	while (!sort_a(stack))
		;

	if (!is_sorted_rev(stack->b, stack->size, stack->b_start, stack->b_used))
		printf("B IS NOT SORTED\n");
	//getchar();

	while (stack->b_used != 0)
	{
		while (stack->b[stack->b_start] > stack->a[stack->a_start])
		{
			ra_swap(stack);
			stack->counter++;
			ft_putstr("RA ++\n");
			// ft_print_both(stack);
			// getchar();
		}
		pa_swap(stack);
		stack->counter++;
		ft_putstr("PA ++\n");
		// ft_print_both(stack);
		// getchar();
		while (!is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
		{
			rra_swap(stack);
			stack->counter++;
			ft_putstr("RRA ++\n");
			// ft_print_both(stack);
			// getchar();
		}
	}
}
