/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_biggest_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:29:45 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/26 18:32:28 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_biggest_int(int *arr, int len)
{
	int i;
	int biggest;

	i = 0;
	biggest = arr[0];
	while (i < len)
	{
		if (arr[i] > biggest)
			biggest = arr[i];
		i++;
	}
	return (biggest);
}