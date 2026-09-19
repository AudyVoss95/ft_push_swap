/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:03:49 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/19 20:08:00 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_detect_flags(char *arg)
{
	if(!ft_strncmp(arg, "--simple", 9))
		return("SIMPLE");
	if(!ft_strncmp(arg, "--medium", 9))
		return("MEDIUM");
	if(!ft_strncmp(arg, "--comlex", 9))
		return("COMPLEX");
	if(!ft_strncmp(arg, "--adaptive", 9))
		return("ADAPTIVE");
	return("ADAPTIVE");		
}