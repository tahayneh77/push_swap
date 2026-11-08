/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:46:58 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:49:46 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_node	*find_min_node(t_stack *stack)
{
	t_node	*cur;
	t_node	*min_node;

	if (!stack || !stack->top)
		return (NULL);
	cur = stack->top;
	min_node = cur;
	while (cur)
	{
		if (cur->val < min_node->val)
			min_node = cur;
		cur = cur->next;
	}
	return (min_node);
}

t_node	*find_max_node(t_stack *stack)
{
	t_node	*cur;
	t_node	*max_node;

	if (!stack || !stack->top)
		return (NULL);
	cur = stack->top;
	max_node = cur;
	while (cur)
	{
		if (cur->val > max_node->val)
			max_node = cur;
		cur = cur->next;
	}
	return (max_node);
}

void	assign_positions(t_stack *stack)
{
	t_node	*cur;
	int		i;
	int		med;

	if (!stack || !stack->top)
		return ;
	cur = stack->top;
	i = 0;
	med = stack->size / 2;
	while (cur)
	{
		cur->pos = i;
		if (i <= med)
			cur->above_med = 1;
		else
			cur->above_med = 0;
		i++;
		cur = cur->next;
	}
}

void	assign_indices(t_stack *stack)
{
	t_node	*cur;
	t_node	*cmp;
	int		rank;

	if (!stack)
		return ;
	cur = stack->top;
	while (cur)
	{
		rank = 0;
		cmp = stack->top;
		while (cmp)
		{
			if (cmp->val < cur->val)
				rank++;
			cmp = cmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}
