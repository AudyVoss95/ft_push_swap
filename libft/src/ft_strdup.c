/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:30:58 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/15 16:42:40 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	void	*allocated_memory;

	s_len = ft_strlen((char *)s);
	allocated_memory = ft_calloc(s_len + 1, sizeof(char));
	if (allocated_memory == NULL)
		return (NULL);
	return ((char *)ft_memcpy(allocated_memory, s, (s_len + 1) * sizeof(char)));
}
