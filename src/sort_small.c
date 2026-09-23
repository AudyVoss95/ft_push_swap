/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 21:00:00 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/20 19:30:17 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top(t_stack *a, t_node *min_node, int pos)
{
	if (pos <= a->size / 2)
	{
		while (a->top != min_node)
			ra(a);
	}
	else
	{
		while (a->top != min_node)
			rra(a);
	}
}

static void	bring_min_to_top(t_stack *a)
{
	t_node	*curr;
	t_node	*min_node;
	int		pos;
	int		i;

	curr = a->top;
	min_node = curr;
	pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->index < min_node->index)
		{
			min_node = curr;
			pos = i;
		}
		i++;
		curr = curr->next;
	}
	rotate_to_top(a, min_node, pos);
}

static void	sort_four_five(t_data *data)
{
	while (data->a.size > 3)
	{
		bring_min_to_top(&data->a);
		pb(&data->a, &data->b);
	}
	sort_three(&data->a);
	while (data->b.size > 0)
		pa(&data->a, &data->b);
}

void	sort_small(t_data *data)
{
	if (data->a.size == 2)
	{
		if (data->a.top->index > data->a.top->next->index)
			sa(&data->a);
	}
	else if (data->a.size == 3)
		sort_three(&data->a);
	else if (data->a.size <= 5)
		sort_four_five(data);
}
