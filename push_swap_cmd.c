/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 04:36:23 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/13 16:06:53 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *get_stack(t_ps *ps, int stack, size_t *size)
{
	int	*stk;

	if (stack == STACK_A)
	{
		stk = ps->stack_a;
		*size = ps->size_a;
	}
	else if (stack == STACK_B)
	{
		stk = ps->stack_b;
		*size = ps->size_b;
	}
	else
		return (NULL);
	
	return (stk);
}

void	swap(t_ps *ps, int stack, int display)
{
	int	tmp;
	int	*stk;
	size_t size;

	stk = get_stack(ps, stack, &size);
	if(!stk)
	{
		printf("error\n");
		return ;
	}
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

void	ss(t_ps *ps)
{
	swap(ps, STACK_A, 0);
	swap(ps, STACK_B, 0);
	write(1, "ss\n", 3);
}

void	rotate(t_ps *ps, int stack, int display)
{
	int	*stk;
	int tmp;
	size_t size;

	stk = get_stack(ps, stack,  &size);
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

void rr(t_ps *ps)
{
	rotate(ps, STACK_A, 0);
	rotate(ps, STACK_B, 0);
	write(1, "rr\n", 3);
}

void	rev_rotate(t_ps *ps, int stack, int display)
{
	int	*stk;
	int tmp;
	size_t size;

	stk = get_stack(ps, stack,  &size);
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

void rrr(t_ps *ps)
{
	rev_rotate(ps, STACK_A, 0);
	rev_rotate(ps, STACK_B, 0);
	write(1, "rrr\n", 4);
}

void pa(t_ps *ps)
{
	int tmp;

	if (ps->size_b == 0)
		return ;
	tmp = ps->stack_b[0];
	ft_memmove(ps->stack_b, &ps->stack_b[1], ps->size_b  * sizeof(int));
	ps->size_b--;
	if(ps->size_a > 0)
		ft_memmove(&ps->stack_a[1], ps->stack_a, ps->size_a  * sizeof(int));
	ps->stack_a[0] = tmp;
	ps->size_a++;
	write(1, "pa\n", 3);
}

void pb(t_ps *ps)
{
	int tmp;

	if (ps->size_a == 0)
		return ;
	tmp = ps->stack_a[0];
	ft_memmove(ps->stack_a, &ps->stack_a[1], ps->size_a * sizeof(int));
	ps->size_a--;
	if(ps->size_b > 0)
		ft_memmove(&ps->stack_b[1], ps->stack_b, ps->size_b * sizeof(int));
	ps->stack_b[0] = tmp;
	ps->size_b++;
	write(1, "pb\n", 3);
}