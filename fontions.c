/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fontions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:47:11 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/29 18:10:21 by hhedjam          ###   ########.fr       */
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
void	current_pos(t_stack	*stack)
{
	int	i;
	int	middle;

	i = 0;
	if(!stack)
		return ;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack -> pos = i;
		if (i <= middle)
			stack -> median = true;
		else
			stack -> median = false;
		stack = stack -> next;
		i++;
	}
}

void	init_node_a(t_stack *a, t_stack *b)
{
	current_pos(a);
	current_pos(b);
	set_target(a,b);
	cost_price(a,b);
	set_cheapest(a);
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

void	set_cheapest(t_stack *stack)
{
	long			cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack-> cost < cheapest_value)
		{
			cheapest_value = stack-> cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
