/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:44:00 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/21 18:26:36 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_list			*temp_node;	

	if (!stack)
		return ;
	while (stack -> top)
	{
		temp_node = stack -> top -> next;
		free(stack -> top);
		stack -> top = temp_node;
	}
	stack -> bottom = NULL;
	stack -> size = 0;
	free(stack);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
	}
	if (!str[i])
	{
		return (0);
	}
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_valid_int(long long nbr)
{
	if (nbr > 2147483647 || nbr < -2147483648)
	{
		return (0);
	}
	return (1);
}

int	ft_verify_args(char *arg)
{
	long long	nbr;

	if (!is_valid_number(arg))
	{
		return (0);
	}
		nbr = ft_atoi(arg);
	if (!is_valid_int(nbr))
	{
		return (0);
	}
	return (1);
}

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}
