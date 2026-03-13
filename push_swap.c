/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:24:54 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/13 05:26:50 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (ERROR);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (ERROR);
	return (i);
}

int	init_stacks(t_ps *ps, int size, char **argv)
{
	size_t	i;

	ps->stack_a = malloc(sizeof(int) * size);
	if (!ps->stack_a)
		return (ERROR);
	ps->stack_b = malloc(sizeof(int) * size);
	if (!ps->stack_b)
	{
		free(ps->stack_a);
		return (ERROR);
	}
	i = 0;
	while (i < (size_t)size)
	{
		ps->stack_a[i] = ft_atoi(argv[i]);
		i++;
	}
	ps->size_a = size;
	ps->size_b = 0;
	return (OK);
}

void	display_stack(t_ps *ps, int stack)
{
	size_t	i;
	size_t	size;
	int		*stk;

	if (stack == STACK_A)
	{
		stk = ps->stack_a;
		size = ps->size_a;
	}
	else if (stack == STACK_B)
	{
		stk = ps->stack_b;
		size = ps->size_b;
	}
	else
		return ;
	i = 0;
	while (i < size)
	{
		printf("%d", stk[i]);
		if (i < size - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	int		size_stack;
	t_ps	ps;

	(void)argc;
	size_stack = check_args(&argv[1]);
	if (size_stack == ERROR
		|| init_stacks(&ps, size_stack, &argv[1]) == ERROR)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	display_stack(&ps, STACK_A);
	pb(&ps);
	display_stack(&ps, STACK_A);
	display_stack(&ps, STACK_B);
	return (0);
}
