/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:01:35 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/13 18:15:47 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	clean_stack(t_ps *ps, int err)
{
	if (ps->stack_a)
	{
		free(ps->stack_a);
		ps->stack_a = NULL;
	}
	if (ps->stack_b)
	{
		free(ps->stack_b);
		ps->stack_b = NULL;
	}
	return (err);
}

int	*get_stack(t_ps *ps, int stack, size_t *size)
{
	int	*stk;

	if (stack == STACK_A)
	{
		stk = ps->stack_a;
		*size = ps->size_a;
	}
	else if (stack == STACK_B)
	{
		stk = ps->stack_b;
		*size = ps->size_b;
	}
	else
		return (NULL);
	return (stk);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	minus;

	minus = 0;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			minus = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (minus)
		return (result * -1);
	return (result);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

void	display_stack(t_ps *ps)
{
	size_t	i;
	size_t	total;

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
