/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 21:50:00 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/20 21:05:16 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*curr;

	if (!stack || !stack->top)
		return (1);
	curr = stack->top;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

static void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*tmp;

	if (!stack || !stack->top)
		return ;
	curr = stack->top;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	clean_exit(t_data *data, int error_code)
{
	free_stack(&data->a);
	free_stack(&data->b);
	if (error_code)
		write(2, "Error\n", 6);
	exit(error_code);
}
