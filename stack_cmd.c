/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 04:36:23 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/13 05:06:25 by cdric.b          ###   ########.fr       */
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
		*size = ps->size_a;
		stk = ps->stack_b;
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
	tmp = stk[0];
	ft_memmove(stk, &stk[1], (size - 1) * sizeof(int));
	stk[size - 1] = tmp;
	if (stack == STACK_A && display == 1)
		write(1, "ra\n", 3);
	else if (stack == STACK_B && display == 1)
		write(1, "rb\n", 3);
}