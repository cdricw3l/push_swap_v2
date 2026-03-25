/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:01:35 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/25 10:57:22 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_ps *ps)
{
	int		i;
	int		total;

	i = 0;
	printf("\n");
	total = (ps->size_a + ps->size_b);
	while (i < ps->size_a)
		printf("%d ", ps->stack_a[i++]);
	while (i < total)
	{
		i++;
		printf(" .");
	}
	printf(" | a\n");
	i = 0;
	while (i < ps->size_b)
		printf("%d ", ps->stack_b[i++]);
	while (i < total)
	{
		i++;
		printf(" .");
	}
	printf(" | b\n\n");
}

int index_of(int *arr, int len, int target)
{
	int i;

	i = 0;
	while (i < len)
	{
		if(arr[i] == target)
			return (i);
		i++;
	}
	return (-1);
}

int find_the_biggest_value(int *arr, int len)
{
	int i;
	int biggest;

	i = 0;
	biggest = arr[0];
	while (i < len)
	{
		if (arr[i] > biggest)
			biggest = arr[i];
		i++;
	}
	return (biggest);
}

int find_the_lowest_value(int *arr, int len)
{
	int i;
	int lowest;

	i = 0;
	lowest = arr[0];
	while (i < len)
	{
		if (arr[i] < lowest)
			lowest = arr[i];
		i++;
	}
	return (lowest);
}

int		get_target_value(int *dest, int dest_size, int value)
{
	int i;
	int target;

	i = 0;
	target = find_the_biggest_value(dest, dest_size);
	if(target < value)
		return (find_the_lowest_value(dest, dest_size));
	while (i < dest_size)
	{
		if (dest[i] < target && dest[i] > value)
			target = dest[i];
		i++;
	}
	return (target);
}

int		get_target_idx(int *dest, int dest_size, int value)
{
	int i;
	int target;
	int target_idx;

	i = 0;
	target = find_the_biggest_value(dest, dest_size);
	if(target < value)
		return (index_of(dest,dest_size,find_the_lowest_value(dest, dest_size)));
	while (i < dest_size)
	{
		if (dest[i] < target && dest[i] > value)
		{
			target = dest[i];
			target_idx = i;
		}
		i++;
	}
	return (target_idx);
}