/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 01:37:13 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/15 16:42:30 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digit(long int n)
{
	int			counter;
	long int	temp;

	if (n == 0)
		return (1);
	counter = 0;
	if (n < 0)
	{
		counter++;
		n *= -1;
	}
	temp = n;
	while (temp != 0)
	{
		temp /= 10;
		counter++;
	}
	return ((size_t) counter);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*str;
	int			digits;

	nb = (long int)n;
	str = ft_calloc(ft_count_digit(nb) + 1, sizeof(char));
	digits = ft_count_digit(nb);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (digits > 0)
	{
		digits--;
		if (str[digits] != '-')
		{
			str[digits] = (nb % 10) + '0';
			nb /= 10;
		}
	}
	return (str);
}
