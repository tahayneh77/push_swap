/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:46:39 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:50:22 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 20)
		return (size / 2);
	if (size <= 100)
		return (15);
	return (32);
}

static void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk, t_bench *bench)
{
	int	i;

	i = 0;
	while (a->size > 0)
	{
		if (a->top->index <= i)
		{
			exec_pb(a, b, bench);
			exec_rb(b, bench);
			i++;
		}
		else if (a->top->index <= i + chunk)
		{
			exec_pb(a, b, bench);
			i++;
		}
		else
			exec_ra(a, bench);
	}
}

static t_node	*find_index_node(t_stack *b, int target_idx)
{
	t_node	*cur;

	cur = b->top;
	while (cur)
	{
		if (cur->index == target_idx)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

static void	push_back_to_a(t_stack *a, t_stack *b, t_bench *bench)
{
	int		target;
	t_node	*target_node;

	target = b->size - 1;
	while (target >= 0)
	{
		assign_positions(b);
		target_node = find_index_node(b, target);
		while (b->top != target_node)
		{
			if (target_node->above_med)
				exec_rb(b, bench);
			else
				exec_rrb(b, bench);
		}
		exec_pa(a, b, bench);
		target--;
	}
}

void	sort_medium(t_stack *a, t_stack *b, t_bench *bench)
{
	int	chunk;

	if (a->size <= 5)
	{
		sort_small(a, b, bench);
		return ;
	}
	assign_indices(a);
	chunk = get_chunk_size(a->size);
	push_chunks_to_b(a, b, chunk, bench);
	push_back_to_a(a, b, bench);
}
