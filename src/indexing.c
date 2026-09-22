/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 19:00:52 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/20 19:49:18 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*check;
	int		count;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		count = 0;
		check = stack->top;
		while (check)
		{
			if (check->value < current->value)
				count++;
			check = check->next;
		}
		current->index = count;
		current = current->next;
	}
}
