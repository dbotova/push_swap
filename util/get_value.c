/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:40:55 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/20 11:40:56 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_next(const int size, const int n)
{
	if (n == size - 1)
		return (0);
	else
		return (n + 1);
}

int	get_mid(const int start, const int size, const int used)
{
	int result;

	result = start + (used / 2);
	if (result > size - 1)
		result = result - size;
	return (result);
}

int	get_max(const int arr[], const int size, const int start, int used)
{
	int max;
	int i;

	i = start;
	max = arr[i];
	while (used)
	{
		max = MAX(max, arr[i]);
		i = get_next(size, i);
		used--;
	}
	return (max);
}

int get_min(const int arr[], const int size, const int start, int used)
{
	int min;
	int i;

	i = start;
	min = arr[i];
	while (used)
	{
		min = MIN(min, arr[i]);
		i = get_next(size, i);
		used--;
	}
	return (min);
}
int	get_after(const int val, const int next, t_stack *stack)
{
	int i;
	int size;

	i = 0;
	size = stack->size;
	if (val == stack->max && next == stack->min)
		return (1);
	if (val > next)
		return (0);
	while (size)
	{
		if (stack->all[i] > val && stack->all[i] < next)
			return (0);
		i++;
		size--;
	}
	return (1);
}