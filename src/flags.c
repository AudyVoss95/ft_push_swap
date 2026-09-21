/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:03:49 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/21 19:13:02 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_detect_flags(char *arg)
{
	if (!ft_strncmp(arg, "--simple", 9))
		return ("SIMPLE");
	if (!ft_strncmp(arg, "--medium", 9))
		return ("MEDIUM");
	if (!ft_strncmp(arg, "--complex", 9))
		return ("COMPLEX");
	if (!ft_strncmp(arg, "--adaptive", 9))
		return ("ADAPTIVE");
	return ("INVALID");
}

int	ft_detect_bench(char *arg)
{
	if (!ft_strncmp(arg, "--bench", 8))
		return (1);
	return (0);
}

int	ft_is_any_flag(t_stack *stack_a, char *flag)
{
	if (ft_detect_bench(flag))
	{
		stack_a -> bench -> bench_mode = 1;
		return (1);
	}
	else if (ft_strncmp(ft_detect_flags(flag), "INVALID", 8))
	{
		stack_a -> bench -> strategy_name = ft_detect_flags(flag);
		return (1);
	}
	return (0);
}
