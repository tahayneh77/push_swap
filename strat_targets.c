/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_targets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:46:09 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:46:13 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_target_b(t_node *a_n, t_stack *b)
{
	t_node	*cur;
	t_node	*target;
	long	diff;
	long	best;

	cur = b->top;
	target = NULL;
	best = LONG_MAX;
	while (cur)
	{
		if (cur->val < a_n->val)
		{
			diff = (long)a_n->val - cur->val;
			if (diff < best)
			{
				best = diff;
				target = cur;
			}
		}
		cur = cur->next;
	}
	if (!target)
		return (find_max_node(b));
	return (target);
}

void	set_targets_b(t_stack *a, t_stack *b)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		cur->target = find_target_b(cur, b);
		cur = cur->next;
	}
}

t_node	*find_target_a(t_node *b_n, t_stack *a)
{
	t_node	*cur;
	t_node	*target;
	long	diff;
	long	best;

	cur = a->top;
	target = NULL;
	best = LONG_MAX;
	while (cur)
	{
		if (cur->val > b_n->val)
		{
			diff = (long)cur->val - b_n->val;
			if (diff < best)
			{
				best = diff;
				target = cur;
			}
		}
		cur = cur->next;
	}
	if (!target)
		return (find_min_node(a));
	return (target);
}
