/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:05:06 by audgiova          #+#    #+#             */
/*   Updated: 2026/08/17 16:42:27 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	long long	nbr;
	int			i;

	i = 1;
	if (argc < 2)
	{
		return (0);
	}
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
		{
			ft_is_error();
			return (0);
		}
		nbr = ft_atoi(argv[i]);
		if (is_valid_int(nbr))
		{
			ft_is_error();
			return (0);
		}
		i++;
	}
	return (0);
}
