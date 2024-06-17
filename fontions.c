/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fontions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:47:11 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/17 18:09:34 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (no_int(argv[i]))
			free_errors(a);
		nbr = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (is_duplicate(*a, (int)n))
			free_errors(a);
		add_node(a, (int)n);
		i++;
	}
}

