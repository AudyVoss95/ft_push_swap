/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:00:41 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/21 14:45:48 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack == NULL || stack->size < 2)
	{
		return ;
	}
	first = stack->top;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	if (second->next != NULL)
	{
		second->next->prev = first;
	}
	else
	{
		stack->bottom = first;
	}
	second->next = first;
	second->prev = NULL;
	stack->top = second;
}

void	sa(t_stack *a)
{
	swap_stack(a);
	ft_printf("sa\n");
	if (a && a->bench)
		a->bench->sa++;
}

void	sb(t_stack *b)
{
	swap_stack(b);
	ft_printf("sb\n");
	if (b && b->bench)
		b->bench->sb++;
}

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	ft_printf("ss\n");
	if (a && a->bench)
		a->bench->ss++;
}
