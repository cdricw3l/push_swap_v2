/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:41:07 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/13 18:12:29 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "assertions/assertions.h"

# define OK      1
# define ERROR   -1

# define STACK_A 0
# define STACK_B 1

#define SS 0
#define RR 1
#define RRR 2

typedef struct s_ps
{
	int		*stack_a;
	int		*stack_b;
	size_t	size_a;
	size_t	size_b;

}	t_ps;

//INITIALISATION
int		init_stacks(t_ps *ps, char **argv);

//UTILS
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		clean_stack(t_ps *ps, int err);
void	display_stack(t_ps *ps);
int		*get_stack(t_ps *ps, int stack, size_t *size);

//COMMANDE

void	push(t_ps *ps, int src, int dst);
void	swap(t_ps *ps, int stack, int display);
void	rotate(t_ps *ps, int stack, int display);
void	rev_rotate(t_ps *ps, int stack, int display);
void	multi_move(t_ps *ps, int move);

#endif