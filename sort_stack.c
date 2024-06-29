/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:07:47 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/29 18:02:18 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack	**a)
{
	t_stack	*max_value;

	max_value = find_max(*a);
	if (max_value == *a)
		ra(a, false);
	else if ((*a) -> next == max_value)
		rra(a, false);
	if ((*a) -> value > (*a) -> next -> value)
		sa(a, false);
}
static void	set_target(t_stack 	*a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b -> value < a -> value && current_b -> value > best_match)
			{
				best_match = current_b -> value;
				target = current_b;
			}
			current_b = current_b -> next;
		}
		if (best_match == LONG_MIN)
			a -> target = find_max(b);
		else
			a -> target = target;
			a = a -> next;
	}
}
bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack-> value > stack-> next-> value)
			return (false);
		stack = stack->next;
	}
	return (true);
}
t_stack	*find_min(t_stack *stack)
{
	long			min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack-> value < min)
		{
			min = stack -> value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node); 
}

t_stack	*find_max(t_stack *stack)
{
	long			max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack-> value > max)
		{
			max = stack-> value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
