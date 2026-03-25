/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 08:14:22 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/25 09:23:19 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_cost(t_ps *s)
{
	int	i;

	i = 0;
	while (i < s->size_a + s->size_b)
	{
		printf(CBLUE"STACK: %d "CRESET, s->cost_arr[STACK + (i * 8)]);
		printf(CCYAN"VALUE: %d "CRESET, s->cost_arr[V + (i * 8)]);
		printf(CGREEN"VALUE_IDX: %d "CRESET, s->cost_arr[V_IDX + (i * 8)]);
		printf(CRED"SSIZE: %d "CRESET, s->cost_arr[SSIZE + (i * 8)]);
		printf(CBLUE"T: %d "CRESET, s->cost_arr[T + (i * 8)]);
		printf(CCYAN"T_IDX: %d "CRESET, s->cost_arr[T_IDX + (i * 8)]);
		printf(CGREEN"D_SIZE: %d "CRESET, s->cost_arr[DSIZE + (i * 8)]);
		printf(CRED"COST: %d "CRESET, s->cost_arr[COST + (i * 8)]);
		NL ;
		i++;
	}
}

void	cost_calculation(t_ps *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->size_a)
	{
		s->cost_arr[STACK + (i * 8)] = STACK_A;
		s->cost_arr[V + (i * 8)] = s->stack_a[i];
		s->cost_arr[V_IDX + (i * 8)] = i;
		s->cost_arr[SSIZE + (i * 8)] = s->size_a;
		s->cost_arr[T + (i * 8)] = get_target_value(s->stack_b, s->size_b, s->stack_a[i]);
		s->cost_arr[T_IDX + (i * 8)] = get_target_idx(s->stack_b, s->size_b, s->stack_a[i]);
		s->cost_arr[DSIZE + (i * 8)] = s->size_b;
		s->cost_arr[COST + (i * 8)] = 0;
		i++;
	}
	j = 0;
	while (j < s->size_b)
	{
		s->cost_arr[STACK + ((j + i) * 8)] = STACK_B;
		s->cost_arr[V + ((j + i) * 8)] = s->stack_b[j];
		s->cost_arr[V_IDX + ((j + i) * 8)] = i;
		s->cost_arr[SSIZE + ((j + i) * 8)] = s->size_b;
		s->cost_arr[T + ((j + i) * 8)] = get_target_value(s->stack_a, s->size_a, s->stack_b[j]);
		s->cost_arr[T_IDX + ((j + i) * 8)] = get_target_idx(s->stack_a, s->size_a, s->stack_b[j]);
		s->cost_arr[DSIZE + ((j + i) * 8)] = s->size_a;
		s->cost_arr[COST + ((j + i) * 8)] = 0;
		j++;
	}
	display_cost(s);
}


//revoir target pour max value