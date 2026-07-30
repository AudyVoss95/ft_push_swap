/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:42:14 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/15 16:42:39 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	lenght;
	char	*result;

	if (!s || !f)
		return (NULL);
	lenght = ft_strlen((char *)s);
	result = (char *)malloc((lenght + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[lenght] = '\0';
	while (lenght > 0)
	{
		result[lenght -1] = f(lenght -1, s[lenght - 1]);
		lenght--;
	}
	return (result);
}
