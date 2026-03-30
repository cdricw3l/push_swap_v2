/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:57:20 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/30 05:06:43 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **argv, int *size)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if ((argv[i][j] == '+' && argv[i][j + 1])
			|| (argv[i][j] == '-' && argv[i][j + 1]))
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (ERROR_ARG);
			j++;
		}
		i++;
		(*size)++;
	}
	return (OK);
}

int	stack_allocation(t_ps *ps, int size)
{
	ps->stack_a = malloc(sizeof(int) * size);
	if (!ps->stack_a)
		return (ERROR_ALLOC);
	ps->stack_b = malloc(sizeof(int) * size);
	if (!ps->stack_b)
	{
		free(ps->stack_a);
		return (ERROR_ALLOC);
	}
	return (OK);
}

int	check_args_validity(char **argv)
{
	int		r;
	int		size;
	char	**arg;
	char	**split;

	size = 0;
	arg = argv;
	while (*arg)
	{
		split = ft_split(*arg, 32);
		if (!split)
			return (ERROR_ALLOC);
		r = check_args(split, &size);
		clean_split(split);
		if (r != OK)
			return (ERROR_ARG);
		arg++;
	}
	return (size);
}

int	process_arg(t_ps *s, char **argv)
{
	int		j;
	int		i;
	char	**arg;
	char	**split;

	i = 0;
	arg = argv;
	while (*arg)
	{
		split = ft_split(*arg, 32);
		if (!split)
			return (ERROR_ALLOC);
		j = 0;
		while (split[j])
			s->stack_a[i++] = ft_atoi(split[j++]);
		clean_split(split);
		arg++;
	}
	return (OK);
}

int	init_stacks(t_ps *ps, char **argv)
{
	int	size;

	size = check_args_validity(argv);
	if (size < 0)
		return (ERROR_ARG);
	ps->size_a = size;
	ps->size_b = 0;
	if (stack_allocation(ps, size) == ERROR_ALLOC)
		return (ERROR_ALLOC);
	if (process_arg(ps, argv) != OK)
		return (clean_stack(ps, ERROR_ARG));
	if (check_duplicate(ps->stack_a, ps->size_a) == ERROR_DUP)
		return (clean_stack(ps, ERROR_DUP));
	return (OK);
}
