/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:47:16 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:47:22 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a, t_bench *bench)
{
	t_node	*max_n;

	max_n = find_max_node(a);
	if (a->top == max_n)
		exec_ra(a, bench);
	else if (a->top->next == max_n)
		exec_rra(a, bench);
	if (a->top->val > a->top->next->val)
		exec_sa(a, bench);
}

static void	push_min_to_b(t_stack *a, t_stack *b, t_bench *bench)
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

static void	sort_four_five(t_stack *a, t_stack *b, t_bench *bench)
{
	while (a->size > 3)
		push_min_to_b(a, b, bench);
	sort_three(a, bench);
	while (b->size > 0)
		exec_pa(a, b, bench);
}

void	sort_small(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->size == 2)
	{
		if (a->top->val > a->top->next->val)
			exec_sa(a, bench);
	}
	else if (a->size == 3)
		sort_three(a, bench);
	else if (a->size <= 5)
		sort_four_five(a, b, bench);
}
