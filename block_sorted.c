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
		get_after(stack->all, stack->b[stack->b_start], stack->a[stack->a_start], stack->size))
		return (1);
	return (0);
}

static void	merge(t_stack *stack)
{
	int max;

	while (stack->b_used != 0)
	{
		max = get_max(stack->b, stack->b_used, stack->b_start);
		while (stack->b[stack->b_start] > stack->a[stack->a_start])
		{
			if (get_after(stack->all, stack->a[stack->a_end], stack->b[stack->b_start], stack->size))
			{
				pa_swap(stack);
				ft_putstr("PA ###\n");
				stack->counter++;
				ft_print_both(stack);
				getchar();
			}
			ra_swap(stack);
			stack->counter++;
			ft_putstr("RA ++\n");
			ft_print_both(stack);
			getchar();
		}
		pa_swap(stack);
		ft_putstr("PA ###\n");
		stack->counter++;
		ft_print_both(stack);
		getchar();
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
	if (is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
		return (1);

	printf("NEW RUN\n");
	ft_print_both(stack);
	getchar();

	while ((get_after(stack->all, stack->a[stack->a_start], stack->a[next], stack->size) ||
		get_after(stack->all, stack->a[stack->a_end], stack->a[stack->a_start], stack->size)) && !check_b(stack))
	{
		ra_swap(stack);
		ft_putstr("RA - 0\n");
		stack->counter++;
		next = get_next(stack->size, stack->a_start);
		ft_print_both(stack);
		getchar();

	}
	
	if (stack->a[stack->a_start] > stack->a[next])
	{
		sa_swap(stack);
		ft_putstr("SA - 1\n");
		next = get_next(stack->size, stack->a_start);
		stack->counter++;
		ft_print_both(stack);
		getchar();
	}
	if (check_b(stack) && stack->b[stack->b_start] != stack->max)
	 {
		next_b = get_next(stack->size, stack->b_start);
	 	mid = get_mid(stack->b_start, stack->size, stack->b_used);
	 	while (check_b(stack) && stack->b[stack->b_start] != stack->max)
	 	{
	 		pa_swap(stack);
			stack->counter++;
			ft_putstr("PA --\n");
			next = get_next(stack->size, stack->a_start);
			ft_print_both(stack);
			getchar();

	 	}
	 	while (get_after(stack->all, stack->a[stack->a_start], stack->a[next], stack->size))
		{
			ra_swap(stack);
			stack->counter++;
			ft_putstr("RA --@\n");
			next = get_next(stack->size, stack->a_start);
			ft_print_both(stack);
			getchar();
		}
		while (stack->a[stack->a_start] < stack->b[stack->b_start] && (stack->a[stack->a_start] > min &&
			stack->b[next_b] != stack->max) && stack->b_used > 1 && stack->a[stack->a_start] != stack->min)
		{
			rb_swap(stack);
			stack->counter++;
			ft_putstr("RB @\n");
			ft_print_both(stack);
			getchar();
		}
	}
	if (!(get_after(stack->all, stack->a[stack->a_end], stack->a[stack->a_start], stack->size)))
	{
		while (!(get_after(stack->all, stack->a[stack->a_end], stack->a[stack->a_start], stack->size)) && stack->a[stack->a_start] < stack->a[next])
		{
			pb_swap(stack);
			ft_putstr("PB\n");
			stack->counter++;
			ft_print_both(stack);
			getchar();
		}
	}
	else
	{
		ra_swap(stack);
		ft_putstr("RA - 4\n");
		stack->counter++;
		ft_print_both(stack);
		getchar();
	}
	return (0);
}

void	sort_arr(t_stack *stack)
{
	int mid;

	while (!sort_a(stack))
		;

	merge(stack);

	// while (stack->b_used != 0)
	// {
	// 	while (stack->b[stack->b_start] > stack->a[stack->a_start])
	// 	{
	// 		ra_swap(stack);
	// 		stack->counter++;
	// 		ft_putstr("RA ++\n");
	// 		ft_print_both(stack);
	// 		getchar();
	// 	}
	// 	pa_swap(stack);
	// 	stack->counter++;
	// 	ft_putstr("PA ++\n");
	// 	ft_print_both(stack);
	// 	getchar();
	// 	mid = get_mid(stack->a_start, stack->size, stack->a_used);
	// 	if (!is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
	// 	{
	// 		if (stack->a[stack->a_start] > stack->a[mid])
	// 		{
	// 			while (!is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
	// 			{
	// 				ra_swap(stack);
	// 				stack->counter++;
	// 				ft_putstr("RA ++\n");
	// 				ft_print_both(stack);
	// 				getchar();
	// 			}
	// 		}
	// 		else while (!is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
	// 		{
	// 			rra_swap(stack);
	// 			stack->counter++;
	// 			ft_putstr("RRA ++\n");
	// 			ft_print_both(stack);
	// 			getchar();
	// 		}
	// 	}
	// }
}
