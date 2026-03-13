/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:57:20 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/13 19:14:42 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (OK);
}

int	check_args(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if ((argv[i][j] == '+' && argv[i][j + 1])
			|| (argv[i][j] == '-' && argv[i][j + 1]))
			i++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (ERROR);
			j++;
		}
		i++;
	}
	if (i < 2 || check_duplicate(argv) == ERROR)
		return (ERROR);
	return (i);
}

int	init_stacks(t_ps *ps, char **argv)
{
	int	i;

	i = check_args(argv);
	if (i == ERROR)
		return (ERROR);
	ps->size_a = i;
	ps->stack_a = malloc(sizeof(int) * i);
	if (!ps->stack_a)
		return (ERROR);
	ps->stack_b = malloc(sizeof(int) * i);
	if (!ps->stack_b)
	{
		free(ps->stack_a);
		return (ERROR);
	}
	i = 0;
	while ((size_t)i < ps->size_a)
	{
		ps->stack_a[i] = ft_atoi(argv[i]);
		i++;
	}
	ps->size_b = 0;
	return (OK);
}
