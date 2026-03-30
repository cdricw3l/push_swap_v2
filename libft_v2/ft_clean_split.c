/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:51:22 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/30 01:51:50 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*clean_split(char **split)
{
	char	**ptr;

	ptr = split;
	while (*ptr)
	{
		if (*ptr)
		{
			free(*ptr);
			*ptr = NULL;
		}
		ptr++;
	}
	free(split);
	split = NULL;
	return (NULL);
}
