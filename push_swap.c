/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:47:43 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:47:48 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_bench(t_bench *bench)
{
	bench->enabled = 0;
	bench->strat = STRAT_DEFAULT;
	bench->chosen = STRAT_DEFAULT;
	bench->disorder = 0.0;
	bench->total_ops = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

static void	select_strategy(t_bench *bench)
{
	if (bench->strat == STRAT_SIMPLE)
		bench->chosen = STRAT_SIMPLE;
	else if (bench->strat == STRAT_MEDIUM)
		bench->chosen = STRAT_MEDIUM;
	else if (bench->strat == STRAT_COMPLEX)
		bench->chosen = STRAT_COMPLEX;
	else
	{
		if (bench->disorder < 0.20)
			bench->chosen = STRAT_SIMPLE;
		else if (bench->disorder < 0.50)
			bench->chosen = STRAT_MEDIUM;
		else
			bench->chosen = STRAT_COMPLEX;
	}
}

static void	run_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	if (bench->chosen == STRAT_SIMPLE)
		sort_simple(a, b, bench);
	else if (bench->chosen == STRAT_MEDIUM)
		sort_medium(a, b, bench);
	else
		sort_complex(a, b, bench);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bench;

	if (argc < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	init_bench(&bench);
	if (!parse_args(argc, argv, &a, &bench))
		ft_error(&a, &b);
	if (a.size == 0)
		return (0);
	bench.disorder = compute_disorder(&a);
	select_strategy(&bench);
	if (!stack_is_sorted(&a))
		run_sort(&a, &b, &bench);
	if (bench.enabled)
		bench_print(&bench);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
