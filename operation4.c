/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:21:37 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/29 19:26:17 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_on_top(t_stack **a)
{
	while ((*a) -> value != find_min(*a) -> value)
	{
		if (find_min(*a)-> median)
			ra(a, false);
		else
			rra(a, false);
	}
}
static void	swap(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack	**a, bool print)
{
	swap(a);
	if (!print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (!print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		write(1, "ss\n", 3);
}
