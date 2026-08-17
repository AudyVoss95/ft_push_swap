/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:44:00 by audgiova          #+#    #+#             */
/*   Updated: 2026/08/17 16:21:55 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_is_error(void)
{
	ft_printf("Error\n");
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
	if (str[i])
	{
		return (0);
	}
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
		{
			return (0);
		}
	}
	return (1);
}

int	is_valid_int(long long nbr)
{
	if (nbr > (int)-1 || nbr < -((int)-1))
	{
		return (0);
	}
	return (1);
}
