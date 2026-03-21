/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_V2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 04:36:23 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/22 00:41:56 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instruction(int stack, void *fonction)
{
	
	if (!ft_strcmp((char *)fonction, "push"))
	{
		if (stack == STACK_A)
			write(1, "pa\n", 3);
		if (stack == STACK_B)
			write(1, "pb\n", 3);
	}
	else if (!ft_strcmp((char *)fonction, "rotate"))
	{
		if (stack == STACK_A)
			write(1, "ra\n", 3);
		if (stack == STACK_B)
			write(1, "rb\n", 3);
		if (stack == STACK_AB)
			write(1, "rr\n", 3);
	}
		
}
void	push(t_ps *s, int stack)

{
	if (stack == STACK_B && s->size_a != 0)
	{
		s->stack_a = s->stack_a + 1;
		s->stack_b = s->stack_a - 1;
		s->size_a--;
		s->size_b++;
		print_instruction(stack, (void *)(__func__));

	}
	if (stack == STACK_A && s->size_b != 0)
	{
		s->stack_a = s->stack_a - 1;
		s->stack_b = s->stack_a - 1;
		s->size_a++;
		s->size_b--;
		print_instruction(stack, (void *)(__func__));

	}
}

void	rotate(t_ps *s, int stack)
{
	int		tmp;
	size_t	size;

	if (stack == STACK_A || stack == STACK_AB)
	{
		tmp = *(s->stack_a);
		size = (s->size_a - 1) * sizeof(int);
		ft_memmove(s->stack_a, s->stack_a + 1, size);
		*(s->stack_a + (s->size_a - 1)) = tmp;
	}
	if (stack == STACK_B || stack == STACK_AB)
	{
		tmp = *(s->stack_b);
		size = (s->size_b - 1) * sizeof(int);
		ft_memmove(s->stack_b - 1, s->stack_b - (s->size_b - 1), size);
		*(s->stack_b - (s->size_b - 1)) = tmp;
	}
	print_instruction(stack, (void *)(__func__));
}
