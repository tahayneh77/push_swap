/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:46:47 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:46:49 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_costs(t_stack *a, t_stack *b)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		if (cur->above_med)
			cur->cost_a = cur->pos;
		else
			cur->cost_a = a->size - cur->pos;
		if (cur->target->above_med)
			cur->cost_b = cur->target->pos;
		else
			cur->cost_b = b->size - cur->target->pos;
		cur = cur->next;
	}
}

static int	node_total_cost(t_node *n)
{
	if (n->above_med == n->target->above_med)
	{
		if (n->cost_a > n->cost_b)
			return (n->cost_a);
		return (n->cost_b);
	}
	return (n->cost_a + n->cost_b);
}

t_node	*find_cheapest(t_stack *a)
{
	t_node	*cur;
	t_node	*cheapest;
	int		min_cost;
	int		cost;

	cur = a->top;
	cheapest = cur;
	min_cost = INT_MAX;
	while (cur)
	{
		cost = node_total_cost(cur);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = cur;
		}
		cur = cur->next;
	}
	return (cheapest);
}

void	rotate_both(t_stack *a, t_stack *b, t_node *cheap, t_bench *bench)
{
	if (cheap->above_med && cheap->target->above_med)
	{
		while (a->top != cheap && b->top != cheap->target)
			exec_rr(a, b, bench);
	}
	else if (!cheap->above_med && !cheap->target->above_med)
	{
		while (a->top != cheap && b->top != cheap->target)
			exec_rrr(a, b, bench);
	}
}

void	finish_rotations(t_stack *a, t_stack *b, t_node *cheap, t_bench *bench)
{
	while (a->top != cheap)
	{
		if (cheap->above_med)
			exec_ra(a, bench);
		else
			exec_rra(a, bench);
	}
	while (b->top != cheap->target)
	{
		if (cheap->target->above_med)
			exec_rb(b, bench);
		else
			exec_rrb(b, bench);
	}
}
