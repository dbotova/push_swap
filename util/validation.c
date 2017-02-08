/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:52:24 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/18 18:52:26 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_size(char **str)
{
	int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

static int input_check(char **str, t_stack *stack)
{
	int *arr;
	int i;
	long long tmp;

	i = 0;
	tmp = 0;
	arr = (int*)malloc(sizeof(int) * RANGE);
	memset(arr, -1, sizeof(int) * RANGE);
	while (i < stack->size)
	{
		if (str[i][0] != '-' && str[i][0] != '+' && !ft_isdigit(str[i][0]))
			return (0);
		else
		{
			tmp = ft_atoi(str[i]);
			if (tmp >= INT_MIN && tmp <= INT_MAX && arr[tmp + UTIL] == -1)
			{
				arr[tmp + UTIL] = 1;
				stack->all[i] = stack->a[i] = tmp;
				if (i == 0)
				{
					stack->min = tmp;
					stack->max = tmp;
				}
				if (tmp < stack->min)
					stack->min = tmp;
				if (tmp > stack->max)
					stack->max = tmp;
			}
			else
				return (0);
		}
		i++;
	}
	SMART_FREE(arr);
	return (1);
}

/*	return -1 if error or duplicate											  */
/*	return positive number as a size 										  */

int	validate(char *str, t_stack **stack)
{
	int size;
	char **result;

	result = ft_strsplit(str, ' ');
	size = get_size(result);
	new_stack(stack, size);
	if (!input_check(result, *stack))
		return (-1);
	ft_strdelall(result);
	return (size);
}
