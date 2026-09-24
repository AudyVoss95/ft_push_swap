/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:37:54 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/23 16:34:43 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (stack == NULL || stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	last = stack->bottom;
	stack->top = second;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	stack->bottom = first;
	return (1);
}

void	ra(t_stack *stack)
{
	if (rotate_stack(stack))
	{
		if (stack && stack->bench)
		{
			stack->bench->ra++;
			stack->bench->total++;
		}
		if (stack->bench->count_only)
			return ;
		ft_printf("ra\n");
	}
}

void	rb(t_stack *stack)
{
	if (rotate_stack(stack))
	{
		if (stack && stack->bench)
		{
			stack->bench->rb++;
			stack->bench->total++;
		}
		if (stack->bench->count_only)
			return ;
		ft_printf("rb\n");
	}
}

void	rr(t_stack *a, t_stack *b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate_stack(a);
	rotated_b = rotate_stack(b);
	if (rotated_a || rotated_b)
	{
		if (a && a->bench)
		{
			a->bench->rr++;
			a->bench->total++;
		}
		if (a->bench->count_only)
			return ;
		ft_printf("rr\n");
	}
}
