/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:20 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/21 19:14:22 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

void		ft_free_stack(t_stack *stack);
int			is_valid_number(char *str);
int			is_valid_int(long long nbr);
int			ft_verify_args(char *arg);
int			ft_error(void);
int			ft_has_duplicate(t_list *list, int num);
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;
typedef struct s_stack
{
	t_list	*top;
	t_list	*bottom;
	int		size;
	t_bench	*bench;
}	t_stack;

void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *a, t_stack *b);
typedef struct s_bench
{
	int		bench_mode;
	double	disorder;
	char	*strategy_name;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;
double		computing_disorder(t_stack *stack_a);
int			ft_get_min_pos(t_stack *stack_a);
void		ft_push_min_to_b(t_stack *a, t_stack *b);
void		ft_simple_sort(t_stack *a, t_stack *b);
char		*ft_detect_flags(char *arg);
int			ft_detect_bench(char *arg);
int			ft_is_any_flag(t_stack *stack_a, char *flag);

#endif