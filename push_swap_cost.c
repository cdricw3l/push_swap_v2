/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 08:14:22 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/29 18:45:13 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_calc(int idx_src, int size_src, int idx_dest, int size_dest)
{
	int	v1;
	int	v2;

	if (idx_dest == idx_src)
		return (idx_dest);
	if (idx_src > (size_src / 2))
		v1 = size_src - idx_src;
	else
		v1 = idx_src;
	if (idx_dest > (size_dest / 2))
		v2 = size_dest - idx_dest;
	else
		v2 = idx_dest;
	return ((v1 + v2) + 1);
}

t_list	**get_cost_list_a(t_ps *s, t_list **lst)
{
	int		i;
	t_cost	*cost;
	t_list	*node;

	i = 0;
	while (i < s->size_a)
	{
		cost = malloc(sizeof(t_cost));
		if (!cost)
			return (NULL);
		cost->stack_value = STACK_A;
		cost->value = s->stack_a[i];
		cost->value_idx = i;
		cost->target_idx = get_target_idx(s->stack_b, s->size_b, s->stack_a[i]);
		cost->target = s->stack_b[cost->target_idx];
		cost->cost = cost_calc(i, s->size_a, cost->target_idx, s->size_b);
		node = ft_lstnew(cost);
		ft_lstadd_back(lst, node);
		i++;
	}
	return (lst);
}

t_list	**get_cost_list_b(t_ps *s, t_list **lst)
{
	int		i;
	t_cost	*cost;
	t_list	*node;

	i = 0;
	while (i < s->size_b)
	{
		cost = malloc(sizeof(t_cost));
		if (!cost)
			return (NULL);
		cost->stack_value = STACK_B;
		cost->value = s->stack_b[i];
		cost->value_idx = i;
		cost->target_idx = get_target_idx(s->stack_a, s->size_a, s->stack_b[i]);
		cost->target = s->stack_a[cost->target_idx];
		cost->cost = cost_calc(i, s->size_b, cost->target_idx, s->size_a);
		node = ft_lstnew(cost);
		ft_lstadd_back(lst, node);
		i++;
	}
	return (lst);
}

t_cost	*lowest_cost(t_list **lst)
{
	t_list	*root;
	t_cost	*cost;

	cost = malloc(sizeof(t_cost));
	if (!cost)
		return (NULL);
	cost->cost = INT_MAX;
	root = *lst;
	while (root)
	{
		if (((t_cost *)root->content)->cost < cost->cost)
			ft_memcpy(cost, ((t_cost *)root->content), sizeof(t_cost));
		root = root->next;
	}
	return (cost);
}

t_cost	*get_best_cost(t_ps *s)
{
	t_list	**lst;
	t_cost	*best_cost;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	*lst = NULL;
	if (!get_cost_list_b(s, lst))
	{
		printf("error\n");
		ft_lstclear(lst, free);
		free(lst);
		return (NULL);
	}
	best_cost = lowest_cost(lst);
	ft_lstclear(lst, free);
	free(lst);
	return (best_cost);
}
