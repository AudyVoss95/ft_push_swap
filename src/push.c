/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:20:50 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/21 18:26:19 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_stack *src, t_stack *dst)
{
	t_list	*node;

	if (src == NULL || src->size == 0)
	{
		return ;
	}
	node = src->top;
	src->top = node->next;
	if (src->top == NULL)
		src->bottom = NULL;
	else
		src->top->prev = NULL;
	src->size--;
	node->next = dst->top;
	node->prev = NULL;
	if (dst->top)
		dst->top->prev = node;
	else
		dst->bottom = node;
	dst->top = node;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push_stack(b, a);
	ft_printf("pa\n");
	if (a && a->bench)
		a->bench->pa++;
}

void	pb(t_stack *a, t_stack *b)
{
	push_stack(a, b);
	ft_printf("pb\n");
	if (a && a->bench)
		a->bench->pb++;
}
