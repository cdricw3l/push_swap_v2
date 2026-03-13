/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:52:56 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/13 13:21:03 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_swap_assertion(char **argv)
{
	t_ps	ps;
	size_t	total_len;
	
	if (init_stacks(&ps, &argv[1]) == ERROR)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	total_len = ps.size_a + ps.size_b;
	display_stack(&ps);
	while (ps.size_a > 0)
	{
		pb(&ps);
		display_stack(&ps);
	}
	assert(ps.size_b == total_len);
	while (ps.size_b > 0)
	{
		pa(&ps);
		display_stack(&ps);
	}
	
	return (clean_stack(&ps, 0));
}
