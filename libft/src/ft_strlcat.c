/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 16:13:45 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/15 16:42:39 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dst_len;
	size_t			src_len;
	size_t			i;

	i = 0;
	src_len = ft_strlen((char *)src);
	dst_len = 0;
	while (dst_len < dstsize && dst[dst_len])
	{
		dst_len++;
	}
	while (src[i] && (dst_len + i + 1) < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len < dstsize)
	{
		dst[dst_len + i] = '\0';
	}
	if (dstsize > dst_len)
	{
		return (dst_len + src_len);
	}
	return (dstsize + src_len);
}
