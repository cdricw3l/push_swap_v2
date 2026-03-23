/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:24:54 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/23 02:46:19 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	init_stacks_v2(t_ps *ps, char **argv, int argc)
{
	int	i;
	
	i = check_args(argv);
	if (i == ERROR)
		return (ERROR);
	
	ps->size_a = argc;
	ps->total_size = argc;

	ps->buffer = malloc(sizeof(int) * argc);
	if (!ps->buffer)
		return (ERROR);
	ps->stack_a = ps->buffer;
	ps->stack_b = ps->buffer;
	i = 0;
	ps->biggest = ft_atoi(argv[i]);
	while (i < ps->size_a)
	{
		ps->buffer[i] = ft_atoi(argv[i]);
		if (ps->buffer[i] > ps->biggest)
			ps->biggest = ps->buffer[i];
		i++;
	}
	ps->size_b = 0;
	return (OK);
}


int is_sort(int *s, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (s[i] > s[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void first_test(t_ps *s)
{
	while (s->size_b < s->size_a)
	{
		if(*s->stack_a != s->biggest)
			push(s, STACK_B);
		else
			rotate(s, STACK_A);
	}
}







int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	
	//t_ps stacks;

	// char *arr_str[101] = {
	// 	"10", "-1", "32", "45", "7", "89", "-23", "56", "0", "14",
	// 	"67", "-45", "23", "9", "100", "-12", "38", "72", "-8", "5",
	// 	"91", "-34", "60", "11", "-99", "27", "44", "-6", "3", "81",
	// 	"19", "-50", "66", "2", "77", "-15", "8", "39", "-2", "95",
	// 	"53", "-7", "21", "64", "-30", "12", "88", "-4", "6", "41",
	// 	"73", "-18", "25", "97", "-11", "1", "58", "-22", "36", "84",
	// 	"-3", "13", "70", "-40", "16", "92", "-14", "28", "54", "-9",
	// 	"4", "80", "-27", "33", "68", "-5", "17", "90", "-16", "42",
	// 	"61", "-35", "24", "79", "-13", "31", "55", "-20", "69", "86",
	// 	"-10", "15", "37", "-28", "62", "93", "-17", "26", "48", "-21", NULL
	// };
	
	// if(init_stacks_v2(&stacks, arr_str, 22) == ERROR)
	// {
	// 	printf("Error\n");
	// 	return (0);
	// }
	// else
	// 	printf(CGREEN"we can start\n"CRESET);

	
	
	return (0);
}
