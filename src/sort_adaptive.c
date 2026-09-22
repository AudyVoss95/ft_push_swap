/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 21:15:00 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/21 20:28:25 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	count_inversions(t_stack *stack)
{
	t_node	*curr;
	t_node	*check;
	long	inversions;

	if (!stack || !stack->top)
		return (0);
	inversions = 0;
	curr = stack->top;
	while (curr)
	{
		check = curr->next;
		while (check)
		{
			if (curr->index > check->index)
				inversions++;
			check = check->next;
		}
		curr = curr->next;
	}
	return (inversions);
}

double	calculate_disorder(t_stack *stack)
{
	long	inversions;
	long	max_inversions;

	if (!stack || stack->size <= 1)
		return (0.0);
	inversions = count_inversions(stack);
	max_inversions = ((long)stack->size * (stack->size - 1)) / 2;
	if (max_inversions == 0)
		return (0.0);
	return ((double)inversions / (double)max_inversions);
}

void	sort_adaptive(t_data *data)
{
	double	disorder;

	if (!data || data->a.size <= 1 || is_sorted(&data->a))
		return ;
	if (data->a.size <= 5)
	{
		sort_small(data);
		return ;
	}
	disorder = calculate_disorder(&data->a);
	if (disorder < 0.15 && data->a.size <= 50)
	{
		sort_simple(data);
		data->bench.strategy = STRAT_ADAPTIVE_S;
	}
	else if (disorder < 0.50 && data->a.size <= 100)
	{
		sort_medium(data);
		data->bench.strategy = STRAT_ADAPTIVE_M;
	}
	else
	{
		sort_complex(data);
		data->bench.strategy = STRAT_ADAPTIVE_C;
	}
}
