/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_interger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 14:51:06 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/21 19:14:03 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_add_numbers(t_stack *stack, char *str)
{
	long long	nbr;

	if (!ft_verify_args(str))
	{
		ft_free_stack(stack);
		return (ft_error());
	}
	nbr = ft_atoi(str);
	if (ft_has_duplicate(stack -> top, (int)nbr))
	{
		ft_free_stack(stack);
		return (ft_error());
	}
	ft_stack_add_back(stack, (int)nbr);
	return (1);
}

int	ft_has_duplicate(t_list *list, int num)
{
	while (list)
	{
		if ((list -> value) == num)
		{
			return (1);
		}
		list = list -> next;
	}
	return (0);
}

int	parse_args(char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int			i;

	i = 1;
	stack_a -> bench -> strategy_name = "ADAPTIVE";
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!ft_is_any_flag(stack_a, argv[i]))
			{
				ft_free_stack(stack_a);
				ft_free_stack(stack_b);
				return (ft_error());
			}
		}
		else if (!ft_add_numbers(stack_a, argv[i]))
		{
			ft_free_stack(stack_b);
			return (ft_error());
		}
		i++;
	}
	return (1);
}

int	ft_verify_node(t_list *node, void *value, t_list **stack)
{
	if (!node)
	{
		free(value);
		ft_is_error(&stack);
		return (0);
	}
	return (1);
}
