/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:44:39 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/29 19:22:53 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		write(1,"rr\n", 3);
}

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack **a , t_stack **b, t_stack *cheapest_node)
{	
	while (*b != cheapest_node-> target && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;
	cheapest_node = get_cheapest(*a); 
	if (cheapest_node -> median && (cheapest_node -> target-> median))
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node -> median) && !(cheapest_node -> target-> median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node-> target, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b, false); 
}
