/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 20:43:04 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/21 20:27:32 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf.h"

typedef struct s_node	t_node;
typedef struct s_stack	t_stack;
typedef struct s_bench	t_bench;
typedef struct s_data	t_data;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE_S,
	STRAT_ADAPTIVE_M,
	STRAT_ADAPTIVE_C
}	t_strategy;

struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				cost;
	t_node			*target;
	t_node			*next;
	t_node			*prev;
};

struct s_bench
{
	int				enabled;
	t_strategy		strategy;
	double			disorder;
	int				total;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
};

struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
	t_bench			*bench;
};

struct s_data
{
	t_stack			a;
	t_stack			b;
	t_bench			bench;
};

int		ft_printf(const char *format, ...);
int		parse_args(int argc, char **argv, t_data *data);
void	clean_exit(t_data *data, int error_code);
void	index_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
int		parse_flag(char *arg, t_bench *bench);
void	print_bench(t_bench *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_small(t_data *data);
void	sort_simple(t_data *data);
void	sort_medium(t_data *data);
void	sort_complex(t_data *data);
void	sort_adaptive(t_data *data);
double	calculate_disorder(t_stack *stack);
void	set_positions(t_stack *stack);
void	update_costs(t_stack *a, t_stack *b);
t_node	*get_cheapest(t_stack *a);
void	move_cheapest_to_b(t_data *data);

#endif