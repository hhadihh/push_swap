/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:52:43 by hhedjam           #+#    #+#             */
/*   Updated: 2024/06/17 18:31:44 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_nbr_char(char *s, char c)
{
	int		count;
	bool	in_word;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (!in_word)
			{
				count++;
				in_word = true;
			}
			s++;
		}
	}
	return (count);
}


static char *get_next_arg(char *s, char c)
{
	static int	current = 0;
	char		*next;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[current] == c)
		current++;
	while ((s[current + len] != c) && s[current + len])
		len++;
	next = malloc((size_t)len * sizeof(char) + 1);
	if (!next)
		return (NULL);
	while ((s[current] != c) && s[current])
		next[i++] = s[current++];
	next[i] = '\0';
	return (next);
}

char	**split(char *s, char c)
{
	int		nbr;
	char	**tab;
	int		i;

	i = 0;
	nbr = count_nbr_char(s, c);
	if (!nbr)
		exit(1);
	tab = malloc(sizeof(char *) * (size_t)(nbr + 2));
	if (!tab)
		return(NULL);
	while (nbr >= 0)
	{
		if (i == 0)
		{
			tab[i] = malloc(sizeof (char));
			if (!tab[i])
				return (NULL);
			tab[i++][0] = '\0';
			continue ;
		}
		tab[i++] = get_next_arg(s, c);
	}
	tab[i] = NULL;
	return (tab);
}
static void	add_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if(!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if(!node)
		return ;
	node -> next = NULL;
	node -> value = n;
	if(!(*stack))
	{
		*stack = node;
		node -> prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*stack);
		last_node = node;
		node -> prev = last_node;
	}
}
t_stack	*ft_lstlast(t_stack	*lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}
