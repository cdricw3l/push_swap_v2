/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:01:35 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/29 15:32:59 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_ps *ps)
{
	int		i;
	int		total;

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

int	get_target_value(int *dest, int dest_size, int value)
{
	int	i;
	int	target;

	i = 0;
	target = ft_biggest_int(dest, dest_size);
	if (target < value)
		return (ft_lowest_int(dest, dest_size, VALUE));
	while (i < dest_size)
	{
		if (dest[i] < target && dest[i] > value)
			target = dest[i];
		i++;
	}
	return (target);
}

int	get_target_idx(int *dest, int dest_size, int value)
{
	int	i;
	int	target;
	int	target_idx;

	i = 0;
	target_idx = 0;
	target = ft_biggest_int(dest, dest_size);
	if (target < value)
		return (ft_lowest_int(dest, dest_size, INDEX));
	while (i < dest_size)
	{
		if (dest[i] <= target && dest[i] > value)
		{
			target = dest[i];
			target_idx = i;
		}
		i++;
	}
	return (target_idx);
}

void	display_node_lst(void *ptr)
{
	t_cost	*node;

	node = (t_cost *)ptr;
	if (node->stack_value == 0)
		printf("Stack: A\n");
	else if (node->stack_value == 1)
		printf("Stack: B\n");
	printf("Value: %d\n", node->value);
	printf("Value idx: %d\n", node->value_idx);
	printf("target: %d\n", node->target);
	printf("Target idx: %d\n", node->target_idx);
	printf("Cost: %d\n", node->cost);
	NL ;
}
