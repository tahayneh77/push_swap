/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:48:43 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/08 08:03:31 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	count_node_mistakes(t_node *i_node, long *pairs)
{
	t_node	*j_node;
	long	mistakes;

	mistakes = 0;
	j_node = i_node->next;
	while (j_node)
	{
		(*pairs)++;
		if (i_node->val > j_node->val)
			mistakes++;
		j_node = j_node->next;
	}
	return (mistakes);
}

double	compute_disorder(t_stack *stack)
{
	t_node	*i_node;
	long	mistakes;
	long	total_pairs;

	if (!stack || stack->size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i_node = stack->top;
	while (i_node)
	{
		mistakes += count_node_mistakes(i_node, &total_pairs);
		i_node = i_node->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}
