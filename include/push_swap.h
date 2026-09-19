/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:20 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/19 17:57:54 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

int			ft_is_error(t_list **list);
int			is_valid_number(char *str);
int			is_valid_int(long long nbr);
int			ft_verify_args(char *arg);
static void	*free_matrix(char **matrix);
int			ft_has_duplicate(t_list *list, int num);
typedef struct	s_list
{
	int				value;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct	s_stack
{
	t_list	*top;
	t_list	*bottom;
	int		size;
}	t_stack;

void sa(t_stack *stack);
void sb(t_stack *stack);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *stack);
void rb(t_stack *stack);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_stack *a, t_stack *b);

#endif