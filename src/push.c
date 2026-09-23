/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:20:50 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/21 21:21:41 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_stack(t_stack *src, t_stack *dst)
{
	t_node	*node;

	if (!src || !dst || src->size == 0)
		return (0);
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
	return (1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push_stack(b, a))
	{
		if (a && a->bench)
		{
			a->bench->pa++;
			a->bench->total++;
		}
		ft_printf("pa\n");
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (push_stack(a, b))
	{
		if (a && a->bench)
		{
			a->bench->pb++;
			a->bench->total++;
		}
		ft_printf("pb\n");
	}
}
