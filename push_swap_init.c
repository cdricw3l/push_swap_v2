/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:57:20 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/29 18:44:55 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(char *argv[])
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strlen(argv[i]) > ft_strlen(argv[j]))
				len = ft_strlen(argv[i]);
			else
				len = ft_strlen(argv[j]);
			if (!ft_strncmp(argv[i], argv[j], len))
			{
				printf("duplicate value: %s et %s index: %d et %d\n",
					argv[i], argv[j], i, j);
				return (ERROR_ARG);
			}
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
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (ERROR_ARG);
			j++;
		}
		i++;
	}
	if (i < 2 || check_duplicate(argv) == ERROR_ARG)
		return (ERROR_ARG);
	return (i);
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

int	init_stacks(t_ps *ps, char **argv)
{
	int	i;

	i = check_args(argv);
	if (i == ERROR_ARG)
		return (ERROR_ARG);
	ps->size_a = i;
	if (stack_allocation(ps, i) == ERROR_ALLOC)
		return (ERROR_ALLOC);
	i = 0;
	while (i < ps->size_a)
	{
		ps->stack_a[i] = ft_atoi(argv[i]);
		i++;
	}
	ps->size_b = 0;
	return (OK);
}
