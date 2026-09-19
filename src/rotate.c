/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:37:54 by andmarqu          #+#    #+#             */
/*   Updated: 2026/08/10 18:37:54 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (stack == NULL || stack->size < 2)
	{
		return ;
	}
	first = stack->top;
	second = first->next;
	last = stack->bottom;
	stack->top = second;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	stack->bottom = first;
}

void ra(t_stack *stack)
{
	rotate_stack(stack);
	ft_printf("ra\n");
}

void rb(t_stack *stack)
{
	rotate_stack(stack);
	ft_printf("rb\n");
}

void rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_printf("rr\n");
}
