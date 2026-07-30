/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:39:58 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/15 16:42:40 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;
	size_t	lenght_s;
	size_t	i;

	lenght_s = ft_strlen((char *)s);
	if (start > lenght_s)
	{
		return ((char *) ft_calloc(1, sizeof(char)));
	}
	if (lenght_s - start < len)
	{
		len = lenght_s - start;
	}
	sub_string = ft_calloc((len + 1), sizeof(char));
	if (sub_string == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_string[i] = s[i + start];
		i++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}
