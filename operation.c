/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:29:47 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/29 18:44:13 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src) -> next;
	if (*src)
		(*src)-> prev = NULL;
	push_node-> prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node-> next = NULL;
	}
	else
	{
		push_node-> next = *dst;
		push_node-> next-> prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b); 
	if (!print) 
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, bool print)
{
	push(b, a);
	if (!print)
		write(1, "pb\n", 3);
}
static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a, bool print)
{
	rev_rotate(a);
	if (!print)
		write(1, "rra\n", 4);
}
