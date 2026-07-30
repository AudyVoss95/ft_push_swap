/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 23:37:07 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/24 22:28:29 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
		{
			i++;
		}
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static void	*free_matrix(char **matrix, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

static void	ft_initialize_vars(size_t *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	int		j;
	int		s_word;

	ft_initialize_vars(&i, &j, &s_word);
	str = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (i <= ft_strlen((char *)s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen((char *)s)) && s_word >= 0)
		{
			str[j] = ft_substr(s, s_word, i - s_word);
			if (!(str[j]))
				return (free_matrix(str, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}
