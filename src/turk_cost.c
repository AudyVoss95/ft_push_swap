/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 19:20:00 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/20 20:24:10 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_stack *stack)
{
	t_node	*curr;
	int		pos;

	if (!stack || !stack->top)
		return ;
	curr = stack->top;
	pos = 0;
	while (curr)
	{
		curr->pos = pos;
		pos++;
		curr = curr->next;
	}
}

static t_node	*find_target_in_b(t_node *a_node, t_stack *b)
{
	t_node	*curr;
	t_node	*target;
	t_node	*max_node;
	int		best_index;

	if (!b || !b->top)
		return (NULL);
	curr = b->top;
	target = NULL;
	max_node = b->top;
	best_index = -1;
	while (curr)
	{
		if (curr->index > max_node->index)
			max_node = curr;
		if (curr->index < a_node->index && curr->index > best_index)
		{
			best_index = curr->index;
			target = curr;
		}
		curr = curr->next;
	}
	if (!target)
		return (max_node);
	return (target);
}

static void	calc_node_cost(t_node *node, t_stack *a, t_stack *b)
{
	int	cost_a;
	int	cost_b;

	if (!node->target)
		return ;
	if (node->pos <= a->size / 2)
		cost_a = node->pos;
	else
		cost_a = a->size - node->pos;
	if (node->target->pos <= b->size / 2)
		cost_b = node->target->pos;
	else
		cost_b = b->size - node->target->pos;
	if ((node->pos <= a->size / 2 && node->target->pos <= b->size / 2)
		|| (node->pos > a->size / 2 && node->target->pos > b->size / 2))
	{
		if (cost_a > cost_b)
			node->cost = cost_a;
		else
			node->cost = cost_b;
	}
	else
		node->cost = cost_a + cost_b;
}

void	update_costs(t_stack *a, t_stack *b)
{
	t_node	*curr;

	if (!a || !b)
		return ;
	set_positions(a);
	set_positions(b);
	curr = a->top;
	while (curr)
	{
		curr->target = find_target_in_b(curr, b);
		calc_node_cost(curr, a, b);
		curr = curr->next;
	}
}

t_node	*get_cheapest(t_stack *a)
{
	t_node	*curr;
	t_node	*cheapest;

	if (!a || !a->top)
		return (NULL);
	curr = a->top;
	cheapest = curr;
	while (curr)
	{
		if (curr->cost < cheapest->cost)
			cheapest = curr;
		curr = curr->next;
	}
	return (cheapest);
}
