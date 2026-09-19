/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computing_disorder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 12:37:50 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/19 20:09:53 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double computing_disorder(t_stack *stack_a)
{
	int	mistakes;
	int	total_pairs;
	t_list	*current;
	t_list	*runner;	
	
	if(!stack_a || stack_a -> top == NULL || stack_a -> size < 2) 
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	current = stack_a -> top;
	while(current-> next != NULL)
	{
		runner = current -> next;
		while(runner != NULL)
		{
			total_pairs++;
			if(current -> value > runner -> value)
				mistakes++;
			runner = runner ->next;
		}
		current = current -> next;		
	}
	return ((double)mistakes / total_pairs);
}
