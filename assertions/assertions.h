/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:18:51 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/13 14:22:57 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERTIONS_H
# define ASSERTIONS_H

# include <assert.h>

#define CRED    "\033[31m"
#define CGREEN  "\033[32m"
#define CYELLOW "\033[33m"
#define CBLUE   "\033[34m"
#define CCYAN   "\033[35m"
#define CRESET  "\033[0m"

int	push_swap_assertion(char **argv);

#endif