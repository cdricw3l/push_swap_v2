/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:50:36 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/25 07:49:35 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tree(t_ps *s, int stack)
{
	if (is_sort(s->stack_a, s->size_a))
		return ;
	if (s->stack_a[0] > s->stack_a[1] && s->stack_a[1] > s->stack_a[2])
	{
		rotate(s, stack);
		swap(s, stack);
	}
	else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] < s->stack_a[2])
		swap(s, stack);
	else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] > s->stack_a[2])
		rev_rotate(s, stack);
	else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2])
	{
		rev_rotate(s, stack);
		swap(s, stack);
	}
	else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[1] < s->stack_a[2])
		rotate(s, stack);
}

void	sort_four(t_ps *s)
{
	int	i;
	int	value;
	int	lowest_idx;

	if (is_sort(s->stack_a, s->size_a))
		return ;
	i = 2;
	while (i-- > 0)
	{
		lowest_idx = find_the_lowest_value_idx(s->stack_a, s->size_a);
		value = lowest_idx[s->stack_a];
		while (s->stack_a[0] != value)
		{
			if (lowest_idx > s->size_a / 2)
				rev_rotate(s, STACK_A);
			else
				rotate(s, STACK_A);
		}
		push(s, STACK_B);
	}
	sort_tree(s, STACK_A);
	if (s->stack_b[0] > s->stack_b[1])
		swap(s, STACK_B);
	push(s, STACK_A);
	push(s, STACK_A);
}

void	bubble_sort(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				ft_swap(&arr[i], &arr[j]);
				j = i + 1;
			}
			else
				j++;
		}
		i++;
	}
}

/*
	
	sort tree:
	//"31", "10", "1",
	//"10", "1", "31",
	//"10", "31", "1",
	//"1", "31", "10",
	//"31", "1", "10",

	five:
	"5" "4" "3" "2" "1"
	"1", "5", "2", "4", "3",
	
*/