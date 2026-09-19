/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:46:34 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/19 19:41:01 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_stack *stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*new_last;

	if (stack == NULL || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->bottom;
	new_last = last->prev;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	new_last->next = NULL;
	stack->top = last;
	stack->bottom = new_last;
}

void rra(t_stack *stack)
{
	reverse_rotate_stack(stack);
	ft_printf("rra\n");
}

void rrb(t_stack *stack)
{
	reverse_rotate_stack(stack);
	ft_printf("rrb\n");
}

void rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	ft_printf("rrr\n");
}