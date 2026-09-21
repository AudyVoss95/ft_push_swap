/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:15:44 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/21 16:03:25 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min_pos(t_stack *stack_a)
{
	int		min_pos;
	int		min_val;
	t_list	*current;
	int		i;

	if (!stack_a || stack_a -> top == NULL)
		return (0);
	current = stack_a -> top;
	min_pos = 0;
	min_val = current -> value;
	i = 0;
	while (current)
	{
		if (current ->value < min_val)
		{
			min_val = current -> value;
			min_pos = i;
		}
		i++;
		current = current -> next;
	}	
	return (min_pos);
}

void	ft_push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = ft_get_min_pos(a);
	if (min_pos <= a ->size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		min_pos = a -> size - min_pos;
		while (min_pos > 0)
		{
			rra(a);
			min_pos--;
		}
	}
	pb(a, b);
}

void	ft_simple_sort(t_stack *a, t_stack *b)
{
	while (a -> size > 1)
	{
		ft_push_min_to_b(a, b);
	}
	while (b -> size > 0)
	{
		pa(a, b);
	}
}
