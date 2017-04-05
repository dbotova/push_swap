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

void	sort_arr(t_stack *stack)
{
	int pivot;
	int counter;

	pivot = stack->a[stack->a_used / 2];
	printf("pivot: %d\n", pivot);
	counter = stack->a_used / 2;
	while (!is_sorted(stack->a, stack->size, stack->a_start, stack->a_used))
	{
		while (stack->a[stack->a_start] > pivot) pb_swap(stack);
		if (stack->a[stack->a_start] < stack->a[stack->a_start + 1])
		{
			if (stack->b[stack->b_start] > stack->b[stack->b_start])
				sb_swap(stack);
			else
				sa_swap(stack);
		}
		else
			ra_swap(stack);
		ft_print_both(stack);
		getchar();
		counter--;
	}
	while (stack->b_used)
		pa_swap(stack);
}
