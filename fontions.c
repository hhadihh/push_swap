/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fontions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:47:11 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/29 17:48:14 by hhedjam          ###   ########.fr       */
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
static void	cost_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a -> cost = a -> pos;
		if (!(a -> median))
			a -> cost = len_a - (a -> pos);
		if (a -> target -> median)
			a -> cost += a -> target -> pos;
		else
			a -> cost += len_b - (a -> target -> pos);
		a = a -> next;
	}
}
