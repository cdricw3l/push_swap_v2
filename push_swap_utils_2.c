/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:01:35 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/22 00:01:11 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_ps *ps)
{
	size_t	i;
	size_t	total;

	i = 0;
	printf("\n");
	total = (ps->size_a + ps->size_b);
	while (i < ps->size_a)
		printf("%d ", ps->stack_a[i++]);
	while (i < total)
	{
		i++;
		printf(" .");
	}
	printf(" | a\n");
	i = 0;
	while (i < ps->size_b)
		printf("%d ", ps->stack_b[i++]);
	while (i < total)
	{
		i++;
		printf(" .");
	}
	printf(" | b\n\n");
}


void display_stack_v2(t_ps *s, int stack)
{
	int size;
	int *ptr;
	char c;

	if (stack == STACK_A)
		ptr = s->stack_a;
	else if(stack == STACK_B)
		ptr = s->stack_b;
	if (stack == STACK_A)
		size = (int)s->size_a;
	else
		size = (int)s->size_b;
	if (stack == STACK_A)
		c = 'A';
	else
		c = 'B';
	NL;
	printf("STACK: %c\n", c);
	while (size > 0)
	{
		NB(*ptr);
		size--;
		if(stack == STACK_A)
			ptr++;
		else if(stack == STACK_B)
			ptr--;
	}
	NL;
}