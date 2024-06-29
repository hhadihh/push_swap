/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:39:02 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/29 18:18:34 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <push_swap.h>

static long	ft_atol(const char *s)
{
	long	res;
	int	signe;

	signe = 1;
	res = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\v' || *s == '\r' || *s == '\f')
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			signe = -signe;
		s++;
	}
	while (ft_isdigit(*s))
	{
		res = res * 10 + (*s - '0');
		*s++;
	}
	if (res > INT_MAX || res < INT_MIN)
		(write(2, "Error", 5), exit(EXIT_FAILURE));
	return (res * signe);
}

int	ft_isdigit(const char *s)
{
	if (*s >= '0' && *s <= '9')
		return (1);
	else
		return (0);
}

int	stack_len(t_stack *stack) 
{
	int	count;

	if (!stack) 
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
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
static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a-> value > b-> value && current_a-> value < best_match)
			{
				best_match = current_a-> value;
				target_node = current_a;
			}
			current_a = current_a-> next;
		}
		if (best_match == LONG_MAX)
			b-> target = find_min(a);
			b-> target = target_node;
		b = b-> next;
	}
}
