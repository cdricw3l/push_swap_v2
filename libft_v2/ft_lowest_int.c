/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowest_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:29:45 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/29 15:28:18 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lowest_int(int *arr, int len, int v_or_i)
{
	int i;
	int lowest_v;
	int lowest_i;

	i = 0;
	lowest_v = arr[0];
	lowest_i = 0;
	while (i < len)
	{
		if (arr[i] < lowest_v)
		{
			lowest_v = arr[i];
			lowest_i = i;
		}
		i++;
	}
	if (v_or_i == INDEX)
		return (lowest_i);
	return (lowest_v);
}
