/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:12:51 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/21 18:25:33 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptive_sort(t_stack *a, t_stack *b)
{
	double	disorder;

	a -> bench ->disorder = computing_disorder(a);
	disorder = a -> bench -> disorder;
	if (disorder == 0.0)
		return ;
	else if (disorder < 0.2)
	{
		a-> bench -> strategy_name = "Adaptive / O(n^2)";
		ft_simple_sort(a, b);
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		a-> bench -> strategy_name = "Adaptive / O(n√n)";
		ft_medium_sorting(a, b);
	}	
	else if (disorder >= 0.5)
	{
		a-> bench -> strategy_name = "Adaptive / O(n log n)";
		ft_complex_sorting(a, b);
	}
}
