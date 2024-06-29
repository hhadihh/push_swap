/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:29:11 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/29 19:32:07 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_stack **stack, t_stack *top_node, char which_stack)
{
	while (*stack != top_node)
	{
		if (which_stack == 'a')
		{
			if (top_node -> median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (which_stack == 'b')
		{
			if (top_node -> median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}
