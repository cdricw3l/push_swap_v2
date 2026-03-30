/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:01:35 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/30 05:08:25 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	clean_stack(t_ps *ps, int err)
{
	if (ps->stack_a)
	{
		free(ps->stack_a);
		ps->stack_a = NULL;
	}
	if (ps->stack_b)
	{
		free(ps->stack_b);
		ps->stack_b = NULL;
	}
	return (err);
}

int	*get_stack(t_ps *ps, int stack, size_t *size)
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

int	check_duplicate(int *stacks, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (stacks[i] == stacks[j])
				return (ERROR_DUP);
			j++;
		}
		i++;
	}
	return (OK);
}
