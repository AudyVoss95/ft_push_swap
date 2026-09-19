/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:05:06 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/19 17:26:47 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	
	stack_a = NULL;
	if (argc < 2)
		return (0);
	if(!parse_args(argc, argv, &stack_a))
	{
		ft_lstclear(&stack_a, free);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}


	return (0);
}
