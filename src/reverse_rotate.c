/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:46:34 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/23 16:34:32 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*new_last;

	if (stack == NULL || stack->size < 2)
		return (0);
	first = stack->top;
	last = stack->bottom;
	new_last = last->prev;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	new_last->next = NULL;
	stack->top = last;
	stack->bottom = new_last;
	return (1);
}

void	rra(t_stack *stack)
{
	if (reverse_rotate_stack(stack))
	{
		if (stack && stack->bench)
		{
			stack->bench->rra++;
			stack->bench->total++;
		}
		if (stack->bench->count_only)
			return ;
		ft_printf("rra\n");
	}
}

void	rrb(t_stack *stack)
{
	if (reverse_rotate_stack(stack))
	{
		if (stack && stack->bench)
		{
			stack->bench->rrb++;
			stack->bench->total++;
		}
		if (stack->bench->count_only)
			return ;
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = reverse_rotate_stack(a);
	rotated_b = reverse_rotate_stack(b);
	if (rotated_a || rotated_b)
	{
		if (a && a->bench)
		{
			a->bench->rrr++;
			a->bench->total++;
		}
		if (a->bench->count_only)
			return ;
		ft_printf("rrr\n");
	}
}
