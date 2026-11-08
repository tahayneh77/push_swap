/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_bounce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:46:53 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:50:11 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_cheapest_to_b(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*cheapest;

	assign_positions(a);
	assign_positions(b);
	set_targets_b(a, b);
	calc_costs(a, b);
	cheapest = find_cheapest(a);
	rotate_both(a, b, cheapest, bench);
	finish_rotations(a, b, cheapest, bench);
	exec_pb(a, b, bench);
}

static void	bounce_to_b(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->size > 3)
		exec_pb(a, b, bench);
	if (a->size > 3)
		exec_pb(a, b, bench);
	while (a->size > 3)
		push_cheapest_to_b(a, b, bench);
}

static void	bounce_back_a(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*target;

	while (b->size > 0)
	{
		assign_positions(a);
		target = find_target_a(b->top, a);
		while (a->top != target)
		{
			if (target->above_med)
				exec_ra(a, bench);
			else
				exec_rra(a, bench);
		}
		exec_pa(a, b, bench);
	}
}

static void	align_min_a(t_stack *a, t_bench *bench)
{
	t_node	*min_n;

	assign_positions(a);
	min_n = find_min_node(a);
	while (a->top != min_n)
	{
		if (min_n->above_med)
			exec_ra(a, bench);
		else
			exec_rra(a, bench);
	}
}

void	sort_complex(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->size <= 5)
	{
		sort_small(a, b, bench);
		return ;
	}
	bounce_to_b(a, b, bench);
	sort_three(a, bench);
	bounce_back_a(a, b, bench);
	align_min_a(a, bench);
}
