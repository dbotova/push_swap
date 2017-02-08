/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:30:30 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/18 18:30:32 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(int ar[], int size, int start, int used)
{
	int next;

	next = 0;
	if (used == 1)
		return (1);
	while (used > 1)
	{
		next = get_next(size, start);
		if (ar[start] > ar[next])
			return (0);
		start = get_next(size, start);
		used--;
	}
	return (1);
}
