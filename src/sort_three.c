/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 20:30:00 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/20 19:24:40 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_index(t_stack *a)
{
	t_node	*curr;
	int		max;

	curr = a->top;
	max = curr->index;
	while (curr)
	{
		if (curr->index > max)
			max = curr->index;
		curr = curr->next;
	}
	return (max);
}

void	sort_three(t_stack *a)
{
	int	max;

	if (!a || a->size < 2)
		return ;
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			sa(a);
		return ;
	}
	max = find_max_index(a);
	if (a->top->index == max)
		ra(a);
	else if (a->top->next->index == max)
		rra(a);
	if (a->top->index > a->top->next->index)
		sa(a);
}
