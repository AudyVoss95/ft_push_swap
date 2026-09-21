/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:12:15 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/21 18:54:19 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_add_back(t_stack *stack, int value)
{
	struct s_list	*new;

	new = (struct s_list *)malloc(sizeof(struct s_list));
	if (!new)
		return ;
	new -> value = value;
	new -> index = stack -> bottom -> index + 1;
	new -> prev = NULL;
	new -> next = NULL;
	if (stack ->top == NULL || stack -> size == 0)
	{
		stack -> top = new;
		stack -> bottom = new;
	}
	else
	{
		new -> prev = stack -> bottom;
		new -> next = NULL;
		stack -> bottom -> next = new;
		stack -> bottom = new;
	}
	stack -> size++;
}

void	ft_stack_add_front(t_stack *stack, int value)
{
	struct s_list	*new;

	new = (struct s_list *)malloc(sizeof(struct s_list));
	if (!new)
		return ;
	new -> value = value;
	new -> prev = NULL;
	new -> next = NULL;
	if (stack ->top == NULL || stack -> size == 0)
	{
		stack -> top = new;
	}
	else
	{
		new -> next = stack -> top;
		new -> prev = NULL;
		stack -> top -> prev = new;
		stack -> top = new;
	}
	stack -> size++;
}
