/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 19:05:26 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/20 20:09:33 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target_pos(t_stack *stack, int target_index)
{
	t_node	*curr;
	int		pos;

	curr = stack->top;
	pos = 0;
	while (curr)
	{
		if (curr->index == target_index)
			return (pos);
		pos++;
		curr = curr->next;
	}
	return (-1);
}

static void	bring_to_top(t_stack *a, int target_index)
{
	int	pos;

	pos = get_target_pos(a, target_index);
	if (pos == -1)
		return ;
	if (pos <= a->size / 2)
	{
		while (a->top->index != target_index)
			ra(a);
	}
	else
	{
		while (a->top->index != target_index)
			rra(a);
	}
}

void	sort_simple(t_data *data)
{
	int	target;
	int	limit;

	if (!data || data->a.size <= 1)
		return ;
	target = 0;
	limit = data->a.size - 1;
	while (target < limit)
	{
		bring_to_top(&data->a, target);
		pb(&data->a, &data->b);
		target++;
	}
	while (data->b.size > 0)
		pa(&data->a, &data->b);
}
