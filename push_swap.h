/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:29 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/29 19:38:01 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				pos;
	bool			median;
	int				cost;
	bool			cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}				t_stack;


// stack init
void	init_stack_a(t_stack **a, char **argv);
void	init_node_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);

// error part

// stack utils

t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
static int	count_nbr_char(char *s, char c);
static char *get_next_arg(char *s, char c);
char	**split(char *s, char c);
static long	ft_atol(const char *s);
static void	add_node(t_stack **stack, int n);
t_stack	*ft_lstlast(t_stack	*lst);
int	ft_isdigit(const char *s);
int	stack_len(t_stack *stack);


//operation

void	prep_for_push(t_stack **stack, t_stack *top_node, char which_stack);
static void	push(t_stack **dst, t_stack **src);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);
static void	rev_rotate(t_stack **stack);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);
static void	rotate(t_stack **stack);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
static void	rev_rotate_both(t_stack **a , t_stack **b, t_stack *cheapest_node);
static void	move_a_to_b(t_stack **a, t_stack **b);
static void	move_b_to_a(t_stack **a, t_stack **b);
static void	min_on_top(t_stack **a);
static void	swap(t_stack **head);
void	sa(t_stack	**a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);


//algo turk

void	current_pos(t_stack	*stack);
void	set_cheapest(t_stack *stack);
static void	cost_price(t_stack *a, t_stack *b);
static void	set_target_a(t_stack 	*a, t_stack *b);
static void	set_target_b(t_stack *a, t_stack *b);


bool	stack_sorted(t_stack *stack);
void	sort_3(t_stack	**a);

#endif