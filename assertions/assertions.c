/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:52:56 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/13 16:12:11 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int push_assert(t_ps	*ps)
{
	size_t	total_len;

	total_len = ps->size_a + ps->size_b;
	printf(CGREEN"\ninital state:\n"CRESET);
	display_stack(ps);
	while (ps->size_a > 0)
		pb(ps);
	assert(ps->size_b == total_len);
	assert(ps->size_a == 0);
	printf(CGREEN"\nafter push b\n"CRESET);
	display_stack(ps);
	while (ps->size_b > 0)
		pa(ps);
	assert(ps->size_b == 0);
	assert(ps->size_a == total_len);
	printf(CGREEN"\nafter push a\n"CRESET);
	display_stack(ps);
	return (0);
}

int rotate_assert(t_ps *ps)
{
	size_t i;
	int initial_value;
	printf(CGREEN"\nRotate A:\n"CRESET);
	display_stack(ps);
	i = 0;
	initial_value = ps->stack_a[0];
	while (i < ps->size_a)
	{
		rotate(ps, STACK_A, 0);
		display_stack(ps);
		i++;
	}
	assert(ps->stack_a[0] == initial_value);
	while (ps->size_a > 0)
		pb(ps);
	i = 0;
	printf(CGREEN"\nRotate B:\n"CRESET);
	display_stack(ps);
	initial_value = ps->stack_b[0];
	while (i < ps->size_b)
	{
		rotate(ps, STACK_B, 0);
		display_stack(ps);
		i++;
	}
	assert(ps->stack_b[0] == initial_value);
	return (0);
}

int rev_rotate_assert(t_ps *ps)
{
	size_t i;
	int initial_value;
	printf(CGREEN"\nRev Rotate B:\n"CRESET);
	i = 0;
	initial_value = ps->stack_b[0];
	display_stack(ps);
	while (i < ps->size_b)
	{
		rev_rotate(ps, STACK_B, 0);
		display_stack(ps);
		i++;
	}
	assert(ps->stack_b[0] == initial_value);
	while (ps->size_b > 0)
		pa(ps);
	i = 0;
	printf(CGREEN"\nRev Rotate A:\n"CRESET);
	display_stack(ps);
	initial_value = ps->stack_a[0];
	while (i < ps->size_a)
	{
		rev_rotate(ps, STACK_A, 0);
		display_stack(ps);
		i++;
	}
	assert(ps->stack_a[0] == initial_value);
	return (0);
}

int rr_assert(t_ps *ps)
{
	size_t	i;
	int		initial_value_a;
	int		initial_value_b;

	while (ps->size_a != ps->size_b)
		pb(ps);
	initial_value_a = ps->stack_a[0];
	initial_value_b = ps->stack_b[0];
	printf(CGREEN"\nrr rotate:\n"CRESET);
	display_stack(ps);
	i = 0;
	while (i < ps->size_a)
	{
		rr(ps);
		display_stack(ps);
		i++;
	}
	assert(ps->stack_a[0] == initial_value_a && ps->stack_b[0] == initial_value_b);
	return (0);
}

int rrr_assert(t_ps *ps)
{
	size_t	i;
	int		initial_value_a;
	int		initial_value_b;

	while (ps->size_a != ps->size_b)
		pb(ps);
	initial_value_a = ps->stack_a[0];
	initial_value_b = ps->stack_b[0];
	printf(CGREEN"\nrrr rotate:\n"CRESET);
	display_stack(ps);
	i = 0;
	while (i < ps->size_a)
	{
		rrr(ps);
		display_stack(ps);
		i++;
	}
	assert(ps->stack_a[0] == initial_value_a && ps->stack_b[0] == initial_value_b);
	return (0);
}

int	swap_assert(t_ps *ps)
{
	int a_1;
	int a_2;
	int b_1;
	int b_2;
	size_t initial_size;
	printf(CGREEN"\nSwap:\n"CRESET);
	a_1 = ps->stack_a[0];
	a_2 = ps->stack_a[1];
	b_1 = ps->stack_b[0];
	b_2 = ps->stack_b[1];
	initial_size = ps->size_a + ps->size_b;
	display_stack(ps);
	swap(ps, STACK_A, 0);
	swap(ps, STACK_B, 0);
	assert(ps->stack_a[0] == a_2 && ps->stack_a[1] == a_1 && ps->stack_b[0] == b_2 && ps->stack_b[1] == b_1);
	display_stack(ps);
	ss(ps);
	assert(ps->stack_a[0] == a_1 && ps->stack_a[1] == a_2 && ps->stack_b[0] == b_1 && ps->stack_b[1] == b_2);
	display_stack(ps);
	while (ps->size_b > 0)
		pa(ps);
	pa(ps);
	swap(ps, STACK_B, 0);
	ss(ps);	
	rrr(ps);
	rr(ps);
	assert(ps->size_b == 0 && ps->size_a == initial_size);
	return (1);
}

int	push_swap_assertion(char **argv)
{
	t_ps	ps;
	
	if (init_stacks(&ps, &argv[1]) == ERROR)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	push_assert(&ps);
	rotate_assert(&ps);
	rev_rotate_assert(&ps);
	rr_assert(&ps);
	rrr_assert(&ps);
	swap_assert(&ps);
	return (clean_stack(&ps, 0));
}
