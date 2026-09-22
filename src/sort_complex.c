/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 19:23:54 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/20 20:04:33 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_target_in_a(t_node *b_node, t_stack *a)
{
	t_node	*curr;
	t_node	*target;
	t_node	*min_node;

	if (!a || !a->top)
		return (NULL);
	curr = a->top;
	target = NULL;
	min_node = a->top;
	while (curr)
	{
		if (curr->index < min_node->index)
			min_node = curr;
		if (curr->index > b_node->index
			&& (!target || curr->index < target->index))
			target = curr;
		curr = curr->next;
	}
	if (!target)
		return (min_node);
	return (target);
}

static void	bring_target_to_top_a(t_stack *a, t_node *target)
{
	set_positions(a);
	if (target->pos <= a->size / 2)
	{
		while (a->top != target)
			ra(a);
	}
	else
	{
		while (a->top != target)
			rra(a);
	}
}

static void	push_back_to_a(t_data *data)
{
	t_node	*target;

	while (data->b.size > 0)
	{
		target = find_target_in_a(data->b.top, &data->a);
		bring_target_to_top_a(&data->a, target);
		pa(&data->a, &data->b);
	}
}

static void	final_align_a(t_stack *a)
{
	t_node	*min_node;

	min_node = a->top;
	while (min_node && min_node->index != 0)
		min_node = min_node->next;
	bring_target_to_top_a(a, min_node);
}

void	sort_complex(t_data *data)
{
	if (!data || data->a.size <= 3)
		return ;
	pb(&data->a, &data->b);
	if (data->a.size > 3)
		pb(&data->a, &data->b);
	while (data->a.size > 3)
	{
		update_costs(&data->a, &data->b);
		move_cheapest_to_b(data);
	}
	sort_three(&data->a);
	push_back_to_a(data);
	final_align_a(&data->a);
}
