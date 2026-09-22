/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 21:30:00 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/20 20:40:23 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_append(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->index = 0;
	new_node->pos = 0;
	new_node->cost = 0;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->prev = stack->bottom;
	if (!stack->top)
		stack->top = new_node;
	else
		stack->bottom->next = new_node;
	stack->bottom = new_node;
	stack->size++;
	return (1);
}

static int	has_duplicate(t_stack *stack, int value)
{
	t_node	*curr;

	curr = stack->top;
	while (curr)
	{
		if (curr->value == value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

static int	parse_nbr(char **str, long *out)
{
	int		sign;
	long	n;

	sign = 1;
	n = 0;
	if (**str == '-')
		sign = -1;
	if (**str == '+' || **str == '-')
		(*str)++;
	if (!(**str >= '0' && **str <= '9'))
		return (0);
	while (**str >= '0' && **str <= '9')
	{
		n = n * 10 + (**str - '0');
		if (n > 2147483648L)
			return (0);
		(*str)++;
	}
	if ((sign == 1 && n > INT_MAX) || (sign == -1 && n > 2147483648L))
		return (0);
	if (**str && **str != ' ' && !(**str >= 9 && **str <= 13))
		return (0);
	*out = n * sign;
	return (1);
}

static int	process_arg(char *str, t_stack *a)
{
	long	num;
	int		found;

	found = 0;
	while (*str)
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (!*str)
			break ;
		if (!parse_nbr(&str, &num))
			return (0);
		if (has_duplicate(a, (int)num) || !stack_append(a, (int)num))
			return (0);
		found = 1;
	}
	return (found);
}

int	parse_args(int argc, char **argv, t_data *data)
{
	int	i;

	if (argc < 2 || !data)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!parse_flag(argv[i], &data->bench))
				return (0);
		}
		else
		{
			if (!process_arg(argv[i], &data->a))
				return (0);
		}
		i++;
	}
	if (data->a.size == 0)
		return (0);
	return (1);
}
