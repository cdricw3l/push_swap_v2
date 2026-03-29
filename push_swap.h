/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:41:07 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/29 18:29:16 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "assertions/assertions.h"
# include "libft_v2/libft.h"

# define OK      1
# define ERROR_ARG   -1
# define ERROR_ALLOC -2

# define STACK_A	0
# define STACK_B	1
# define STACK_AB	2

#define SS 0
#define RR 1
#define RRR 2

#define NL printf("\n")
#define NB(n) printf("%d ",n)
#define	DEBBUG printf(CRED"debug\n"CRESET)

enum field
{
	STACK,
	V,
	V_IDX,
	SSIZE,
	T,
	T_IDX,
	DSIZE,
	COST
};


typedef struct s_ps
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;

}	t_ps;

typedef struct s_cost
{
	int stack_value;
	int value;
	int value_idx;
	int	target;
	int	target_idx;
	int cost;
	
} t_cost;

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

void	push(t_ps *ps, int src, int dst);
void	swap(t_ps *ps, int stack, int display);
void	rotate(t_ps *ps, int stack, int display);
void	rev_rotate(t_ps *ps, int stack, int display);
void	multi_move(t_ps *ps, int move);


//UTILS_V2

int		get_target_value(int *dest, int dest_size, int value);
int		get_target_idx(int *dest, int dest_size, int value);
int		find_the_biggest_value(int *arr, int len);
void	display_node_lst(void *ptr);

// COST

t_cost	*get_best_cost(t_ps *s);
int 	index_of(int *arr, int len, int target);

//algo

void	push_swap(t_ps *s);
void	sort_tree(t_ps *s, int stack);
void	sort_four(t_ps *s);

#endif