/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:19:44 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/15 16:42:31 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
		{
			return ((void *)(ptr));
		}
		ptr++;
		i++;
	}
	return (NULL);
}
