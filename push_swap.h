/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:41:07 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/25 07:48:27 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "assertions/assertions.h"

#define CRED    "\033[31m"
#define CGREEN  "\033[32m"
#define CYELLOW "\033[33m"
#define CBLUE   "\033[34m"
#define CCYAN   "\033[35m"
#define CRESET  "\033[0m"

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
	int		*cost_arr;
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;

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
int		find_the_lowest_value_idx(int *arr, int len);
int		is_sort(int *s, int len);
int		get_target_idx(int *arr, int len, int value);
int 	get_mediane(int *arr, int len);

void 	print_arr(int *arr, int len);
//algo

void	sort_four(t_ps *s);
void	sort_tree(t_ps *s, int stack);
void	bubble_sort(int *arr, int len);
void	push_swap_v1(t_ps *s);
void 	push_swap_v2(t_ps *s);

//sort


#endif