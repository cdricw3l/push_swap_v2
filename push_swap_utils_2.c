/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:01:35 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/23 02:46:24 by cdric.b          ###   ########.fr       */
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