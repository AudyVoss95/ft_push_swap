/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmarqu <andmarqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 21:40:00 by andmarqu          #+#    #+#             */
/*   Updated: 2026/09/20 21:05:47 by andmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_data(t_data *data)
{
	data->a.top = NULL;
	data->a.bottom = NULL;
	data->a.size = 0;
	data->a.bench = &data->bench;
	data->b.top = NULL;
	data->b.bottom = NULL;
	data->b.size = 0;
	data->b.bench = &data->bench;
	data->bench.enabled = 0;
	data->bench.strategy = STRAT_ADAPTIVE;
	data->bench.disorder = 0.0;
	data->bench.total = 0;
	data->bench.sa = 0;
	data->bench.sb = 0;
	data->bench.ss = 0;
	data->bench.pa = 0;
	data->bench.pb = 0;
	data->bench.ra = 0;
	data->bench.rb = 0;
	data->bench.rr = 0;
	data->bench.rra = 0;
	data->bench.rrb = 0;
	data->bench.rrr = 0;
}

static void	run_complex(t_data *data)
{
	if (data->a.size == 2)
	{
		if (data->a.top->index > data->a.top->next->index)
			sa(&data->a);
	}
	else if (data->a.size == 3)
		sort_three(&data->a);
	else
		sort_complex(data);
}

static void	dispatch_sort(t_data *data)
{
	if (data->bench.strategy == STRAT_SIMPLE)
		sort_simple(data);
	else if (data->bench.strategy == STRAT_MEDIUM)
		sort_medium(data);
	else if (data->bench.strategy == STRAT_COMPLEX)
		run_complex(data);
	else
		sort_adaptive(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	init_data(&data);
	if (!parse_args(argc, argv, &data))
		clean_exit(&data, 1);
	index_stack(&data.a);
	data.bench.disorder = calculate_disorder(&data.a);
	if (!is_sorted(&data.a))
		dispatch_sort(&data);
	print_bench(&data.bench);
	clean_exit(&data, 0);
	return (0);
}
