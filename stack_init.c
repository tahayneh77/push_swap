/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:47:05 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:50:40 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

t_node	*node_new(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = val;
	node->index = 0;
	node->pos = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->above_med = 0;
	node->target = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	stack_push_bottom(t_stack *stack, int val)
{
	t_node	*node;

	node = node_new(val);
	if (!node)
		return (0);
	if (!stack->top)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->bottom->next = node;
		node->prev = stack->bottom;
		stack->bottom = node;
	}
	stack->size++;
	return (1);
}

void	stack_clear(t_stack *stack)
{
	t_node	*cur;
	t_node	*tmp;

	if (!stack)
		return ;
	cur = stack->top;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

int	stack_is_sorted(t_stack *stack)
{
	t_node	*cur;

	if (!stack || stack->size <= 1)
		return (1);
	cur = stack->top;
	while (cur->next)
	{
		if (cur->val > cur->next->val)
			return (0);
		cur = cur->next;
	}
	return (1);
}
