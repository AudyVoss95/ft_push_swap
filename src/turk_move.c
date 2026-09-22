/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 19:45:00 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/20 20:25:05 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both_up(t_data *data, t_node *cheapest)
{
	while (data->a.top != cheapest && data->b.top != cheapest->target)
		rr(&data->a, &data->b);
}

static void	rotate_both_down(t_data *data, t_node *cheapest)
{
	while (data->a.top != cheapest && data->b.top != cheapest->target)
		rrr(&data->a, &data->b);
}

static void	finish_a(t_stack *a, t_node *cheapest)
{
	while (a->top != cheapest)
	{
		if (cheapest->pos <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
}

static void	finish_b(t_stack *b, t_node *target)
{
	while (b->top != target)
	{
		if (target->pos <= b->size / 2)
			rb(b);
		else
			rrb(b);
	}
}

void	move_cheapest_to_b(t_data *data)
{
	t_node	*cheapest;

	if (!data)
		return ;
	cheapest = get_cheapest(&data->a);
	if (!cheapest || !cheapest->target)
		return ;
	if (cheapest->pos <= data->a.size / 2
		&& cheapest->target->pos <= data->b.size / 2)
		rotate_both_up(data, cheapest);
	else if (cheapest->pos > data->a.size / 2
		&& cheapest->target->pos > data->b.size / 2)
		rotate_both_down(data, cheapest);
	finish_a(&data->a, cheapest);
	finish_b(&data->b, cheapest->target);
	pb(&data->a, &data->b);
}
