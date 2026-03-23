/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:41:07 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/23 02:47:00 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "assertions/assertions.h"

# define OK      1
# define ERROR   -1

# define STACK_A	0
# define STACK_B	1
# define STACK_AB	2

#define SS 0
#define RR 1
#define RRR 2

#define NL printf("\n")
#define NB(n) printf("%d ",n)
#define	DEBBUG printf(CRED"debug\n"CRESET)

typedef struct s_ps
{
	int 	*buffer;
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	int		biggest;
	int		total_size;

}	t_ps;

//INITIALISATION
int		init_stacks(t_ps *ps, char **argv);
int		check_args(char *argv[]);

//UTILS
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_swap(int *a, int *b);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		clean_stack(t_ps *ps, int err);
void	display_stack(t_ps *ps);
int		*get_stack(t_ps *ps, int stack, size_t *size);
int     ft_strcmp(const char *s1, const char *s2);

//COMMANDE

void	push_v1(t_ps *ps, int src, int dst);
void	swap_v1(t_ps *ps, int stack, int display);
void	rotate_v1(t_ps *ps, int stack, int display);
void	rev_rotate_v1(t_ps *ps, int stack, int display);
void	multi_move_v1(t_ps *ps, int move);

// Commande V2

void	push(t_ps *s, int stack);
void	swap(t_ps *s, int stack);
void	rotate(t_ps *s, int stack);
void	rev_rotate(t_ps *s, int stack);
void	display_stack_v2(t_ps *s, int stack);
void	print_instruction(t_ps *s, int stack, void *fonction);

//UTILS_V2

int		get_target(int *arr, int len, int value);
int		find_the_biggest_value(int *arr, int len);

#endif