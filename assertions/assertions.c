/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:52:56 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/23 02:44:49 by cdric.b          ###   ########.fr       */
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
		push(ps,STACK_A,STACK_B);
	assert(ps->size_b == total_len);
	assert(ps->size_a == 0);
	printf(CGREEN"\nafter push b\n"CRESET);
	display_stack(ps);
	while (ps->size_b > 0)
		push(ps,STACK_B,STACK_A);
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
		push(ps, STACK_A, STACK_B);
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
		push(ps, STACK_B, STACK_A);
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
		push(ps, STACK_A, STACK_B);
	initial_value_a = ps->stack_a[0];
	initial_value_b = ps->stack_b[0];
	printf(CGREEN"\nrr rotate:\n"CRESET);
	display_stack(ps);
	i = 0;
	while (i < ps->size_a)
	{
		multi_move(ps, RR);
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
		push(ps, STACK_A, STACK_B);
	initial_value_a = ps->stack_a[0];
	initial_value_b = ps->stack_b[0];
	printf(CGREEN"\nrrr rotate:\n"CRESET);
	display_stack(ps);
	i = 0;
	while (i < ps->size_a)
	{
		multi_move(ps, RRR);
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
	multi_move(ps, SS);
	assert(ps->stack_a[0] == a_1 && ps->stack_a[1] == a_2 && ps->stack_b[0] == b_1 && ps->stack_b[1] == b_2);
	display_stack(ps);
	while (ps->size_b > 0)
		push(ps, STACK_B, STACK_A);
	push(ps, STACK_B, STACK_A);
	swap(ps, STACK_B, 0);
	multi_move(ps, SS);	
	multi_move(ps, RRR);	
	multi_move(ps, RR);	
	assert(ps->size_b == 0 && ps->size_a == initial_size);
	return (1);
}

int init_and_check_assertion(void)
{
	t_ps	ps;
	int		r;
	
	char *args_1[] = {"1", "2", "133", "12", NULL};
	r = init_stacks(&ps, args_1);
	assert(r == OK);
	clean_stack(&ps, 0);
	char *args_2[] = {"1", "1", "1", "12", NULL};
	r = init_stacks(&ps, args_2);
	assert(r == ERROR);
	char *args_3[] = {"11", "2", "1", "1", NULL};
	r = init_stacks(&ps, args_3);
	assert(r == ERROR);
	char *args_4[] = {"1", "2", "11", "1", NULL};
	r = init_stacks(&ps, args_4);
	assert(r == ERROR);
	char *args_5[] = {"-1", "2", "+11", "1", NULL};
	r = init_stacks(&ps, args_5);
	assert(r == OK);
	clean_stack(&ps, 0);
	char *args_6[] = {"-", "2", "+", "1", NULL};
	r = init_stacks(&ps, args_6);
	assert(r == ERROR);
	
	return (1);
}

void get_target_assertion()
{
	int arr_int[] = {
		101, -1 , 32, 45, 7,  89, -23, 56, 0,  14,
		67, -45 , 23, 9, 100, -12, 38, 72, -8, 55,
		91, 340
	};

	int target;
	target = get_target(arr_int, sizeof(arr_int) / sizeof(arr_int[0]), 55);
	assert(target == 56);
	target = get_target(arr_int, sizeof(arr_int) / sizeof(arr_int[0]), 3);
	assert(target == 7);
	target = get_target(arr_int, sizeof(arr_int) / sizeof(arr_int[0]), 100);
	assert(target == 101);
	target = get_target(arr_int, sizeof(arr_int) / sizeof(arr_int[0]), 29);
	assert(target == 32);
	target = get_target(arr_int, sizeof(arr_int) / sizeof(arr_int[0]), 24);
	assert(target == 32);
}


int	push_swap_assertion(char **argv)
{
	//t_ps	ps;
	(void)argv;
	init_and_check_assertion();
	// if (init_stacks(&ps, &argv[1]) == ERROR)
	// {
	// 	write(1, "Error\n", 6);
	// 	return (1);
	// }
	// push_assert(&ps);
	// rotate_assert(&ps);
	// rev_rotate_assert(&ps);
	// rr_assert(&ps);
	// rrr_assert(&ps);
	// swap_assert(&ps);
	//clean_stack(&ps, 0)
	return (0);
}
