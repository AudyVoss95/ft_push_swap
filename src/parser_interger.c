/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_interger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 14:51:06 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/19 19:29:59 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_add_numbers(t_list **stack, char *str)
{
	long long	nbr;
	int			*value;
	t_list 		*new_node;
	
	if (!ft_verify_args(str))
		return (ft_is_error(stack));
	nbr = ft_atoi(str);
	if (ft_has_duplicate(*stack, (int)nbr))
		return (ft_is_error(stack));
	*value = (int)nbr;
	new_node = ft_lstnew(value);
	if (!ft_verify_node(new_node, value,  stack))
		return (0);
	ft_lstadd_back(stack, new_node);
	return (1);
}

int	ft_has_duplicate(t_list *list, int num)
{
	while(list)
	{
		if(*(int *)(list -> value) == num)
		{
			return (1);
		}
		list  = list -> next;
	}
	return(0);
}

int	parse_args(char **argv, t_list **stack)
{
	int			i;
	
	i = 1;
	while (argv[i])
	{
		if(!ft_add_numbers(stack, argv[i]))
		{
			return (ft_is_error(stack));
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
