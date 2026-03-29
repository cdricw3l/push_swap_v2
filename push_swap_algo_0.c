/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:50:36 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/29 18:45:43 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tree(t_ps *s, int stack)
{
	if (ft_issort(s->stack_a, s->size_a))
		return ;
	if (s->stack_a[0] > s->stack_a[1] && s->stack_a[1] > s->stack_a[2])
	{
		rotate(s, stack, 1);
		swap(s, stack, 1);
	}
	else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] < s->stack_a[2])
		swap(s, stack, 1);
	else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] > s->stack_a[2])
		rev_rotate(s, stack, 1);
	else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2])
	{
		rev_rotate(s, stack, 1);
		swap(s, stack, 1);
	}
	else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[1] < s->stack_a[2])
		rotate(s, stack, 1);
}

void	sort_four(t_ps *s)
{
	int	i;
	int	value;
	int	lowest_idx;

	if (ft_issort(s->stack_a, s->size_a))
		return ;
	i = 2;
	while (i-- > 0)
	{
		lowest_idx = ft_lowest_int(s->stack_a, s->size_a, INDEX);
		value = lowest_idx[s->stack_a];
		while (s->stack_a[0] != value)
		{
			if (lowest_idx > s->size_a / 2)
				rev_rotate(s, STACK_A, 1);
			else
				rotate(s, STACK_A, 1);
		}
		push(s, STACK_B, 1);
	}
	sort_tree(s, STACK_A);
	if (s->stack_b[0] > s->stack_b[1])
		swap(s, STACK_B, 1);
	push(s, STACK_A, 1);
	push(s, STACK_A, 1);
}
