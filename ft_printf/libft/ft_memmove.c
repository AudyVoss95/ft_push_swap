/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:06:39 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/15 16:42:34 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	if (!dest && !src)
		return (ptr_dest);
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			ptr_dest[n] = ptr_src[n];
		}
	}
	else
	{
		while (n--)
		{
			*ptr_dest = *ptr_src;
			ptr_dest++;
			ptr_src++;
		}
	}
	return (dest);
}
