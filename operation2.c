/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:40:45 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/29 18:45:09 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **b, bool print)
{
	rev_rotate(b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		write(1, "rrr\n", 4);
}

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}		

void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (!print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (!print)
		write(1, "rb\n", 3);
}
