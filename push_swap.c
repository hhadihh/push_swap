/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:54:28 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/29 20:04:51 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return(1);
	else if (argc == 2)
		argv = split(argv[1], ' ' );
	init_stack_a(&a, argv + 1);
	if (!stack_good(a))
	{
		if(stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_3(&a);
		else
			sort_stack(&a, &b);
	}
	free__stack(&a);
	return(0);
}