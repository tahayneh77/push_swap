/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:48:18 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/08 08:43:16 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to(t_stack *dst, t_stack *src)
{
	t_node	*node;

	if (!src || !src->top)
		return ;
	node = src->top;
	src->top = node->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	node->next = dst->top;
	node->prev = NULL;
	if (dst->top)
		dst->top->prev = node;
	else
		dst->bottom = node;
	dst->top = node;
	dst->size++;
}
