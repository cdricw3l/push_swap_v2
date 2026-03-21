/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:24:54 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/22 00:39:40 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	init_stacks_v2(t_ps *ps, char **argv, int argc)
{
	int	i;

	// i = check_args(argv);
	// if (i == ERROR)
	// 	return (ERROR);
	ps->size_a = argc;
	ps->total_size = argc;
	ps->stack_a = malloc(sizeof(int) * argc);
	if (!ps->stack_a)
		return (ERROR);
	ps->stack_b = ps->stack_a - 1 ;
	i = 0;
	while ((size_t)i < ps->size_a)
	{
		ps->stack_a[i] = ft_atoi(argv[i]);
		i++;
	}
	ps->size_b = 0;
	return (OK);
}







int	main(int argc, char **argv)
{
	(void) argc;

	t_ps stacks;


	if(init_stacks_v2(&stacks, &argv[1], argc - 1) == ERROR)
	{
		printf("Error\n");
		return (0);
	}
	push(&stacks, STACK_B);
	push(&stacks, STACK_B);
	push(&stacks, STACK_B);
	
	rotate(&stacks, STACK_A);
	rotate(&stacks, STACK_B);
	rotate(&stacks, STACK_AB);
	
	push(&stacks, STACK_A);
	push(&stacks, STACK_A);
	push(&stacks, STACK_A);
	push(&stacks, STACK_A);
	push(&stacks, STACK_A);
	
	NL;
	
	
	
	return (0);
}
