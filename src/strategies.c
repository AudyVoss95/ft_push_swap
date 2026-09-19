/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:15:44 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/19 20:24:54 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_pos(t_stack *stack_a)
{
	int 	min_pos;
	int 	min_val;
	t_list 	*current;

	if(!stack_a || stack_a -> top == NULL || stack_a -> size < 2) 
		return (0);
	current = stack_a -> top;
	min_pos = current -> index;
	min_val = current -> value;
	while(current)
	{
		current = current -> next;
	}

	
}