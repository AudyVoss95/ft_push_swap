/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:42:30 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/15 16:42:40 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	end = ft_strlen((char *)s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
	{
		end--;
	}
	if (start > end)
		return ((char *)ft_calloc(1, sizeof(char)));
	return (ft_substr(s1, start, (end - start)));
}
