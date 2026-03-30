/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:24:54 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/30 05:07:56 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		r;
	t_ps	stacks;

	(void) argc;
	r = init_stacks(&stacks, &argv[1]);
	if (r < 0)
	{
		printf("Error\n");
		return (1);
	}
	push_swap(&stacks);
	assert(ft_issort(stacks.stack_a, stacks.size_a));
	return (clean_stack(&stacks, 0));
}
