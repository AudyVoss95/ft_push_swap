/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:00:41 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/23 16:34:59 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack == NULL || stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	if (second->next != NULL)
		second->next->prev = first;
	else
		stack->bottom = first;
	second->next = first;
	second->prev = NULL;
	stack->top = second;
	return (1);
}

void	sa(t_stack *a)
{
	if (swap_stack(a))
	{
		if (a && a->bench)
		{
			a->bench->sa++;
			a->bench->total++;
		}
		if (a->bench->count_only)
			return ;
		ft_printf("sa\n");
	}
}

void	sb(t_stack *b)
{
	if (swap_stack(b))
	{
		if (b && b->bench)
		{
			b->bench->sb++;
			b->bench->total++;
		}
		if (b->bench->count_only)
			return ;
		ft_printf("sb\n");
	}
}

void	ss(t_stack *a, t_stack *b)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = swap_stack(a);
	swapped_b = swap_stack(b);
	if (swapped_a || swapped_b)
	{
		if (a && a->bench)
		{
			a->bench->ss++;
			a->bench->total++;
		}
		if (a->bench->count_only)
			return ;
		ft_printf("ss\n");
	}
}
