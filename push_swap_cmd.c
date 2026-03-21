/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 04:36:23 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/22 00:25:08 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_v1(t_ps *ps, int stack, int display)
{
	int		tmp;
	int		*stk;
	size_t	size;

	stk = get_stack(ps, stack, &size);
	if (!stk)
		return ;
	if (size < 2)
		return ;
	tmp = stk[0];
	stk[0] = stk[1];
	stk[1] = tmp;
	if (stack == STACK_A && display == 1)
		write(1, "sa\n", 3);
	else if (stack == STACK_B && display == 1)
		write(1, "sb\n", 3);
}

void	rotate_v1(t_ps *ps, int stack, int display)
{
	int		tmp;
	int		*stk;
	size_t	size;

	stk = get_stack(ps, stack, &size);
	if (size == 0)
		return ;
	tmp = stk[0];
	ft_memmove(stk, &stk[1], (size - 1) * sizeof(int));
	stk[size - 1] = tmp;
	if (stack == STACK_A && display == 1)
		write(1, "ra\n", 3);
	else if (stack == STACK_B && display == 1)
		write(1, "rb\n", 3);
}

void	rev_rotate_v1(t_ps *ps, int stack, int display)
{
	int		tmp;
	int		*stk;
	size_t	size;

	stk = get_stack(ps, stack, &size);
	if (size == 0)
		return ;
	tmp = stk[size - 1];
	ft_memmove(&stk[1], stk, (size - 1) * sizeof(int));
	stk[0] = tmp;
	if (stack == STACK_A && display == 1)
		write(1, "rra\n", 4);
	else if (stack == STACK_B && display == 1)
		write(1, "rrb\n", 4);
}

void	push_v1(t_ps *ps, int src, int dst)
{
	int		tmp;
	int		*src_stack;
	int		*dst_stack;
	size_t	size_src;
	size_t	size_dst;

	src_stack = get_stack(ps, src, &size_src);
	dst_stack = get_stack(ps, dst, &size_dst);
	if (size_src == 0)
		return ;
	tmp = src_stack[0];
	ft_memmove(src_stack, &src_stack[1], size_src * sizeof(int));
	if (size_dst > 0)
		ft_memmove(&dst_stack[1], dst_stack, size_dst * sizeof(int));
	dst_stack[0] = tmp;
	if (dst == STACK_A)
	{
		ps->size_b--;
		ps->size_a++;
		write(1, "pa\n", 3);
		return ;
	}
	ps->size_a--;
	ps->size_b++;
	write(1, "pb\n", 3);
}

void	multi_move_v1(t_ps *ps, int move)
{
	if (move == SS)
	{
		swap_v1(ps, STACK_A, 0);
		swap_v1(ps, STACK_B, 0);
		write(1, "ss\n", 3);
	}
	else if (move == RR)
	{
		rotate_v1(ps, STACK_A, 0);
		rotate_v1(ps, STACK_B, 0);
		write(1, "rr\n", 3);
	}
	else if (move == RRR)
	{
		rev_rotate_v1(ps, STACK_A, 0);
		rev_rotate_v1(ps, STACK_B, 0);
		write(1, "rrr\n", 4);
	}
	return ;
}
