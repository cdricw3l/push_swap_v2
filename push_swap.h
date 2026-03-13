/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:41:07 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/13 04:20:20 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <assert.h>

# define ERROR   -1
# define OK      1
# define STACK_A 0
# define STACK_B 1

typedef struct s_ps
{
	int		*stack_a;
	int		*stack_b;
	size_t	size_a;
	size_t	size_b;

}	t_ps;

int	ft_isdigit(int c);
int	ft_atoi(const char *str);

#endif