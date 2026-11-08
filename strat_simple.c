/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:46:31 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:50:19 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_elem(t_stack *a, t_stack *b, t_bench *bench)
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
	exec_pb(a, b, bench);
}

void	sort_simple(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->size <= 5)
	{
		sort_small(a, b, bench);
		return ;
	}
	while (a->size > 3)
		push_min_elem(a, b, bench);
	sort_three(a, bench);
	while (b->size > 0)
		exec_pa(a, b, bench);
}
