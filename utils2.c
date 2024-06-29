/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:39:02 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/29 17:52:59 by hhedjam          ###   ########.fr       */
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
