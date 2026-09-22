/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:05:06 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/21 19:26:09 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a -> bench = &stack_b -> bench;
	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &stack_a, &stack_b) || stack_a -> size == 0)
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (ft_error());
	}
	return (0);
}
