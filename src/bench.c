/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:47:12 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/21 18:26:30 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	bench->bench_mode = 0;
	bench->disorder = 0.0;
	bench->strategy_name = NULL;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

int	total_operations(t_bench *b)
{
	return (b->sa + b->sb + b->ss + b->pa + b->pb
		+ b->ra + b->rb + b->rr + b->rra + b->rrb + b->rrr);
}

void	get_strategy(char *strategy, t_bench *bench, char *flag)
{
	strategy = ft_detect_flags(flag);
	bench -> strategy_name = strategy;
}
