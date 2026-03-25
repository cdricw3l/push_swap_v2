/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:01:35 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/24 02:48:59 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display_stack_v2(t_ps *s, int stack)
{
	int size;
	int *ptr;

	if (stack == STACK_A)
		ptr = s->stack_a;
	else if(stack == STACK_B)
		ptr = s->stack_b;
	if (stack == STACK_A)
		size = (int)s->size_a;
	else
		size = (int)s->size_b;
	while (size > 0)
	{
		NB(*ptr);
		size--;
		if(stack == STACK_A)
			ptr++;
		else if(stack == STACK_B)
			ptr--;
	}
	NL;
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

int find_the_lowest_value_idx(int *arr, int len)
{
	int i;
	int lowest_idx;
	int lowest_value;

	i = 0;
	lowest_idx = 0;
	lowest_value = arr[0];
	while (i < len)
	{
		if (arr[i] < lowest_value)
		{
			lowest_value = arr[i];
			lowest_idx = i;
		}
		i++;
	}
	return (lowest_idx);
}

int		get_target(int *arr, int len, int value)
{
	int i;
	int target;

	i = 0;
	target = find_the_biggest_value(arr, len);
	while (i < len)
	{
		if (arr[i] < target && arr[i] > value)
			target = arr[i];
		i++;
	}
	return (target);
}

int		get_target_idx(int *arr, int len, int value)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

int is_sort(int *s, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (s[i] > s[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
