/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:50:36 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/29 19:09:16 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b(t_ps *s, t_cost *cost)
{
	int	i;

	i = cost->value_idx;
	if (i < s->size_b / 2)
	{
		while (i > 0)
		{
			rotate(s, STACK_B, 1);
			i--;
		}
		return ;
	}
	while (i < s->size_b)
	{
		rev_rotate(s, STACK_B, 1);
		i++;
	}
}

void	move_a(t_ps *s, t_cost *cost)
{
	int	i;

	i = cost->target_idx;
	if (i <= s->size_a / 2)
	{
		while (i > 0)
		{
			rotate(s, STACK_A, 1);
			i--;
		}
		return ;
	}
	while (i < s->size_a)
	{
		rev_rotate(s, STACK_A, 1);
		i++;
	}
}

void	double_move(t_ps *s, t_cost *cost)
{
	int	i;

	i = cost->target_idx;
	if (i <= s->size_a / 2)
	{
		while (i > 0)
		{
			multi_move(s, RR);
			i--;
		}
		return ;
	}
	while (i < s->size_a)
	{
		multi_move(s, RRR);
		i++;
	}
}

void	back_to_zero(t_ps *s)
{
	int	low;

	low = ft_lowest_int(s->stack_a, s->size_a, INDEX);
	if (low <= s->size_a / 2)
	{
		while (low > 0)
		{
			rotate(s, STACK_A, 1);
			low--;
		}
	}
	else
	{
		while (low < s->size_a)
		{
			rev_rotate(s, STACK_A, 1);
			low++;
		}
	}
}

void adjust_stack(t_ps *s, t_cost *cost)
{
	int lowest;

	if(cost->target_idx <= s->size_a / 2  && cost->value_idx <= s->size_b / 2)
	{
		if(cost->target_idx < cost->value_idx)
			lowest = cost->target_idx;
		else
			lowest = cost->value_idx;
		while (lowest > 0)
		{
			multi_move(s, RR);
			lowest--;
			cost->target_idx--;
			cost->value_idx--;
		}
	}
	// else if (cost->target_idx > s->size_a / 2  && cost->value_idx > s->size_b / 2)
	// {
	// 	if(cost->target_idx > cost->value_idx)
	// 		lowest = cost->target_idx;
	// 	else
	// 		lowest = cost->value_idx;
	// 	while (lowest > 0)
	// 	{
	// 		multi_move(s, RR);
	// 		lowest--;
	// 		cost->target_idx--;
	// 		cost->value_idx--;
	// 	}
	// }
}

void	push_swap(t_ps *s)
{
	t_cost	*best;

	while (s->size_a > 3)
		push(s, STACK_A, STACK_B);
	sort_tree(s, STACK_A);
	while (s->size_b > 0)
	{
		best = get_best_cost(s);
		if (best->value_idx == best->target_idx)
			double_move(s, best);
		else
		{
			adjust_stack(s, best);
			move_a(s, best);
			move_b(s, best);
		}
		assert(s->stack_a[0] == best->target && s->stack_b[0] == best->value);
		push(s, STACK_B, STACK_A);
		free(best);
	}
	back_to_zero(s);
}
