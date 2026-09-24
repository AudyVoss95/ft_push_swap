/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 21:10:00 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/23 16:37:36 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void	put_metric(char *pre, long val, char *suf)
{
	char	c;

	while (*pre)
		write(2, pre++, 1);
	if (val < 0)
	{
		write(2, "-", 1);
		val = -val;
	}
	if (val >= 10)
		put_metric("", val / 10, "");
	c = (val % 10) + '0';
	write(2, &c, 1);
	while (*suf)
		write(2, suf++, 1);
}

int	parse_flag(char *arg, t_bench *bench)
{
	if (!arg || !bench)
		return (0);
	if (ft_strcmp(arg, "--simple") == 0)
		bench->strategy = STRAT_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		bench->strategy = STRAT_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		bench->strategy = STRAT_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		bench->strategy = STRAT_ADAPTIVE;
	else if (ft_strcmp(arg, "--bench") == 0)
		bench->enabled = 1;
	else if (ft_strcmp(arg, "--count-only") == 0)
		bench->count_only = 1;
	else
		return (0);
	return (1);
}

static void	print_meta(t_bench *b)
{
	long	val;

	val = (long)(b->disorder * 10000.0 + 0.5);
	put_metric("[bench] disorder: ", val / 100, ".");
	if ((val % 100) < 10)
		write(2, "0", 1);
	put_metric("", val % 100, "%\n");
	if (b->strategy == STRAT_SIMPLE)
		ft_putstr_fd("[bench] strategy: Simple / O(n^2)\n", 2);
	else if (b->strategy == STRAT_MEDIUM)
		ft_putstr_fd("[bench] strategy: Medium / O(n*sqrt(n))\n", 2);
	else if (b->strategy == STRAT_COMPLEX)
		ft_putstr_fd("[bench] strategy: Complex / O(n log n)\n", 2);
	else if (b->strategy == STRAT_ADAPTIVE_S)
		ft_putstr_fd("[bench] strategy: Adaptive / O(n^2)\n", 2);
	else if (b->strategy == STRAT_ADAPTIVE_C)
		ft_putstr_fd("[bench] strategy: Adaptive / O(n log n)\n", 2);
	else if (b->strategy == STRAT_ADAPTIVE_M)
		ft_putstr_fd("[bench] strategy: Adaptive / O(n*sqrt(n))\n", 2);
}

void	print_bench(t_bench *b)
{
	if (b ->count_only)
	{
		ft_putnbr_fd(b->total, 1);
	}
	if (!b || !b->enabled)
		return ;
	print_meta(b);
	put_metric("[bench] total_ops: ", b->total, "\n");
	put_metric("[bench] sa: ", b->sa, " ");
	put_metric("sb: ", b->sb, " ");
	put_metric("ss: ", b->ss, " ");
	put_metric("pa: ", b->pa, " ");
	put_metric("pb: ", b->pb, "\n");
	put_metric("[bench] ra: ", b->ra, " ");
	put_metric("rb: ", b->rb, " ");
	put_metric("rr: ", b->rr, " ");
	put_metric("rra: ", b->rra, " ");
	put_metric("rrb: ", b->rrb, " ");
	put_metric("rrr: ", b->rrr, "\n");
}
