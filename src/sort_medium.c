/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 18:00:00 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/20 20:54:05 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (32);
}

static void	push_chunks_to_b(t_data *data)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = get_chunk_size(data->a.size);
	while (data->a.size > 0)
	{
		if (data->a.top->index <= i)
		{
			pb(&data->a, &data->b);
			rb(&data->b);
			i++;
		}
		else if (data->a.top->index <= i + chunk)
		{
			pb(&data->a, &data->b);
			i++;
		}
		else
			ra(&data->a);
	}
}

static int	get_pos_in_b(t_stack *b, int target)
{
	t_node	*curr;
	int		pos;

	curr = b->top;
	pos = 0;
	while (curr)
	{
		if (curr->index == target)
			return (pos);
		pos++;
		curr = curr->next;
	}
	return (-1);
}

static void	bring_to_top_b(t_stack *b, int target)
{
	int	pos;

	pos = get_pos_in_b(b, target);
	if (pos <= b->size / 2)
	{
		while (b->top->index != target)
			rb(b);
	}
	else
	{
		while (b->top->index != target)
			rrb(b);
	}
}

void	sort_medium(t_data *data)
{
	int	target;

	push_chunks_to_b(data);
	while (data->b.size > 0)
	{
		target = data->b.size - 1;
		bring_to_top_b(&data->b, target);
		pa(&data->a, &data->b);
	}
}
