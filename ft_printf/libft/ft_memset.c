/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:13:56 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/15 16:42:39 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*pointer;
	size_t	i;

	pointer = (char *)s;
	i = 0;
	while (i < n)
	{
		pointer[i] = c;
		i++;
	}
	return ((void *)pointer);
}
