/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:52:56 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/13 12:31:32 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_swap_assertion(char **argv)
{
	t_ps	ps;
	
	if (init_stacks(&ps, &argv[1]) == ERROR)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	display_stack(&ps, STACK_A);
	pb(&ps);
	display_stack(&ps, STACK_A);
	display_stack(&ps, STACK_B);
	return (clean_stack(&ps, 0));
}
